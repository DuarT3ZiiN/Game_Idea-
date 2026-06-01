#include "TaskScheduler.h"

void TaskScheduler::Initialize(
    uint32_t WorkerCount
)
{
    Workers.Initialize(
        WorkerCount,
        &Queue
    );
}

void TaskScheduler::Shutdown()
{
    Workers.Shutdown();
}

void TaskScheduler::Submit(
    const Job& InJob
)
{
    Queue.Push(InJob);
}
