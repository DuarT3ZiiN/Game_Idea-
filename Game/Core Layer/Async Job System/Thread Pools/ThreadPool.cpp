#include "ThreadPool.h"

void ThreadPool::Initialize(
    const ThreadPoolConfig& Config
)
{
    Settings = Config;

    for (
        uint32_t i = 0;
        i < Settings.WorkerCount;
        ++i
    )
    {
        auto Worker =
            std::make_unique<AsyncWorker>(
                &Queue
            );

        Worker->Start();

        Workers.push_back(
            std::move(Worker)
        );
    }
}

void ThreadPool::Shutdown()
{
    for (auto& Worker : Workers)
    {
        Worker->Stop();
    }

    Workers.clear();
}

void ThreadPool::Submit(
    const AsyncJob& Job
)
{
    Queue.Push(Job);
}

