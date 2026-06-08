#include "BackgroundJobSystem.h"

#include <thread>
#include <chrono>

void BackgroundJobSystem::Initialize(const ThreadPoolConfig& Config)
{
    GeneralPool.Initialize(Config);

    // Pool dedicado para saves: 1 worker sempre disponível
    ThreadPoolConfig SaveConfig;
    SaveConfig.WorkerCount          = 1;
    SaveConfig.bDedicatedSaveWorker = false; // já é dedicado
    SavePool.Initialize(SaveConfig);
}

void BackgroundJobSystem::Shutdown()
{
    WaitForAll();

    GeneralPool.Shutdown();
    SavePool.Shutdown();
}

bool BackgroundJobSystem::SubmitBackgroundJob(const AsyncJob& Job)
{
    // Jobs de save vão para o pool exclusivo
    if (Job.Type == EAsyncJobType::SaveGame)
        return SavePool.Submit(Job);

    return GeneralPool.Submit(Job);
}

void BackgroundJobSystem::WaitForAll()
{
    // Polling com sleep curto — adequado para shutdown (não é hot path)
    while (!GeneralPool.IsIdle() || !SavePool.IsIdle())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

uint32_t BackgroundJobSystem::GetPendingCount() const
{
    return GeneralPool.GetQueueSize() + SavePool.GetQueueSize();
}