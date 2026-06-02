#include "TaskScheduler.h"

#include <algorithm>
#include <cassert>

void TaskScheduler::Initialize(uint32_t WorkerCount)
{
    assert(!bInitialized && "TaskScheduler já foi inicializado");

    if (WorkerCount == 0)
    {
        const uint32_t HardwareThreads =
            std::thread::hardware_concurrency();

        // Reserva 1 thread para o main thread
        WorkerCount = (HardwareThreads > 1)
            ? HardwareThreads - 1
            : 1;
    }

    Workers.Initialize(WorkerCount, &Queue, &Profiler);

    bInitialized = true;
}

void TaskScheduler::Shutdown()
{
    if (!bInitialized)
        return;

    // Acorda todos os workers bloqueados em WaitAndPop
    Queue.SignalShutdown();

    Workers.Shutdown();

    bInitialized = false;
}

bool TaskScheduler::Submit(const Job& InJob)
{
    assert(bInitialized && "TaskScheduler não foi inicializado");
    return Queue.Push(InJob);
}

void TaskScheduler::SubmitBatch(const Job* Jobs, uint32_t Count)
{
    assert(bInitialized && "TaskScheduler não foi inicializado");

    for (uint32_t i = 0; i < Count; ++i)
        Queue.Push(Jobs[i]);
}

void TaskScheduler::EndFrame()
{
    BudgetManager.ResetFrame();
    Profiler.ResetPeaks();
    Dependencies.Clear();
}

PerformanceMonitor& TaskScheduler::GetPerformanceMonitor()
{
    return Profiler;
}

RuntimeBudgetManager& TaskScheduler::GetBudgetManager()
{
    return BudgetManager;
}