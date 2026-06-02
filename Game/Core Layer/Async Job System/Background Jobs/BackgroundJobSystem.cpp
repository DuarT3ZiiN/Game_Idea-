#include "BackgroundJobSystem.h"

void BackgroundJobSystem::Initialize()
{
    ThreadPoolConfig Config;

    Config.WorkerCount =
        std::thread::hardware_concurrency() - 2;

    Pool.Initialize(Config);
}

void BackgroundJobSystem::Shutdown()
{
    Pool.Shutdown();
}

void BackgroundJobSystem::SubmitBackgroundJob(
    const AsyncJob& Job
)
{
    Pool.Submit(Job);
}

