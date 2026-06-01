#include "WorkerPool.h"

void WorkerPool::Initialize(
    uint32_t WorkerCount,
    PriorityJobQueue* Queue
)
{
    for (uint32_t i = 0;
         i < WorkerCount;
         ++i)
    {
        auto Worker =
            std::make_unique<WorkerThread>(
                Queue
            );

        Worker->Start();

        Workers.push_back(
            std::move(Worker)
        );
    }
}

void WorkerPool::Shutdown()
{
    for (auto& Worker : Workers)
    {
        Worker->Stop();
    }

    Workers.clear();
}
