#include "WorkerThread.h"

#include <chrono>

#include "PriorityJobQueue.h"
#include "PerformanceMonitor.h"

WorkerThread::WorkerThread(
    PriorityJobQueue*   InQueue,
    PerformanceMonitor* InMonitor
)
    : Running(false)
    , Queue(InQueue)
    , Monitor(InMonitor)
{
}

WorkerThread::~WorkerThread()
{
    Stop();
}

void WorkerThread::Start()
{
    Running = true;
    Thread  = std::thread(&WorkerThread::Run, this);
}

void WorkerThread::Stop()
{
    Running = false;

    if (Thread.joinable())
        Thread.join();
}

void WorkerThread::Run()
{
    while (Running)
    {
        Job CurrentJob;

        // WaitAndPop dorme quando não há jobs — sem busy-wait
        if (!Queue->WaitAndPop(CurrentJob))
            break; // shutdown sinalizado

        if (!CurrentJob.Execute)
            continue;

        // ── Execução com medição de tempo ─────────────────
        const auto StartTime = std::chrono::high_resolution_clock::now();

        CurrentJob.Execute();

        const auto EndTime = std::chrono::high_resolution_clock::now();

        // ── Registra tempo no monitor ──────────────────────
        if (Monitor && CurrentJob.DebugName && *CurrentJob.DebugName != '\0')
        {
            const double ElapsedMS = std::chrono::duration<double, std::milli>(
                EndTime - StartTime
            ).count();

            Monitor->RegisterTime(CurrentJob.DebugName, ElapsedMS);
        }

        // ── Marca como concluído ───────────────────────────
        if (CurrentJob.bCompleted)
            CurrentJob.bCompleted->store(true, std::memory_order_release);

        // ── Notifica sistemas dependentes ──────────────────
        if (CurrentJob.OnComplete)
            CurrentJob.OnComplete(CurrentJob.ID);
    }
}