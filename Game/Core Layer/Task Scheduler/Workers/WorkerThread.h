#pragma once

#include <thread>
#include <atomic>

class PriorityJobQueue;
class PerformanceMonitor;

// WorkerThread é um worker do pool que fica em loop consumindo jobs.
//
// Melhorias em relação à versão anterior:
//   - Chama Job::OnComplete após Execute (notifica sistemas dependentes)
//   - Marca Job::bCompleted = true após execução (polling no main thread)
//   - Mede tempo de execução e reporta ao PerformanceMonitor (pode ser nullptr)
//   - Usa WaitAndPop para dormir quando idle (não busy-wait)
//   - Stop() envia shutdown via PriorityJobQueue para acordar o worker

class WorkerThread
{
public:

    WorkerThread(
        PriorityJobQueue*   InQueue,
        PerformanceMonitor* InMonitor = nullptr
    );

    ~WorkerThread();

    void Start();
    void Stop();

private:

    void Run();

private:

    std::thread         Thread;
    std::atomic<bool>   Running;

    PriorityJobQueue*   Queue;
    PerformanceMonitor* Monitor;
};