#include "AsyncJobManager.h"

void AsyncJobManager::Initialize()
{
    BackgroundSystem.Initialize();
}

void AsyncJobManager::Shutdown()
{
    BackgroundSystem.Shutdown();
}

void AsyncJobManager::Submit(
    const AsyncJob& Job
)
{
    BackgroundSystem
        .SubmitBackgroundJob(Job);
}