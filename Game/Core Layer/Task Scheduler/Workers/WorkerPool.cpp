#include "WorkerPool.h"
#include "PriorityJobQueue.h"

void WorkerPool::Initialize(
    uint32_t            WorkerCount,
    PriorityJobQueue*   Queue,
    PerformanceMonitor* Monitor
)
{
    Workers.reserve(WorkerCount);

    for (uint32_t i = 0; i < WorkerCount; ++i)
    {
        auto Worker = std::make_unique<WorkerThread>(Queue, Monitor);
        Worker->Start();
        Workers.push_back(std::move(Worker));
    }
}

void WorkerPool::Shutdown()
{
    for (auto& Worker : Workers)
        Worker->Stop();

    Workers.clear();
}

uint32_t WorkerPool::GetWorkerCount() const
{
    return static_cast<uint32_t>(Workers.size());
}