#include "ThreadPool.h"

void ThreadPool::Initialize(const ThreadPoolConfig& Config)
{
    Settings = Config;

    const uint32_t Count = Settings.ResolvedWorkerCount();

    Workers.reserve(Count);

    for (uint32_t i = 0; i < Count; ++i)
    {
        auto Worker = std::make_unique<AsyncWorker>(&Queue);
        Worker->Start();
        Workers.push_back(std::move(Worker));
    }
}

void ThreadPool::Shutdown()
{
    // Acorda todos os workers bloqueados em WaitAndPop antes de parar
    Queue.SignalShutdown();

    for (auto& Worker : Workers)
        Worker->Stop();

    Workers.clear();
}

bool ThreadPool::Submit(const AsyncJob& Job)
{
    return Queue.Push(Job);
}

uint32_t ThreadPool::GetWorkerCount() const
{
    return static_cast<uint32_t>(Workers.size());
}

uint32_t ThreadPool::GetQueueSize() const
{
    return Queue.GetSize();
}

bool ThreadPool::IsIdle() const
{
    return Queue.Empty();
}