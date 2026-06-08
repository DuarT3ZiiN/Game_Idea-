#include "AsyncJobManager.h"

void AsyncJobManager::Initialize(const ThreadPoolConfig& Config)
{
    BackgroundSystem.Initialize(Config);
}

void AsyncJobManager::Shutdown()
{
    BackgroundSystem.Shutdown();

    std::lock_guard<std::mutex> Lock(TrackingMutex);
    TrackedJobs.clear();
}

AsyncJobID AsyncJobManager::Submit(const AsyncJob& InJob)
{
    AsyncJob Job = InJob;

    // Garante que o job tem State compartilhado para tracking
    if (!Job.State)
    {
        Job.State = std::make_shared<std::atomic<EAsyncJobState>>(
            EAsyncJobState::Pending
        );
    }

    // Registra antes de submeter para evitar race condition
    {
        std::lock_guard<std::mutex> Lock(TrackingMutex);
        TrackedJobs[Job.ID] = Job.State;
    }

    Job.State->store(EAsyncJobState::Queued, std::memory_order_release);

    if (!BackgroundSystem.SubmitBackgroundJob(Job))
    {
        // Fila cheia — remove do tracking e retorna inválido
        std::lock_guard<std::mutex> Lock(TrackingMutex);
        TrackedJobs.erase(Job.ID);
        return INVALID_ASYNC_JOB;
    }

    return Job.ID;
}

EAsyncJobState AsyncJobManager::GetJobState(AsyncJobID ID) const
{
    std::lock_guard<std::mutex> Lock(TrackingMutex);

    auto It = TrackedJobs.find(ID);

    if (It == TrackedJobs.end())
        return EAsyncJobState::Completed; // não rastreado = concluído ou inexistente

    return It->second->load(std::memory_order_acquire);
}

bool AsyncJobManager::IsJobComplete(AsyncJobID ID) const
{
    const EAsyncJobState State = GetJobState(ID);
    return State == EAsyncJobState::Completed
        || State == EAsyncJobState::Failed
        || State == EAsyncJobState::Cancelled;
}

void AsyncJobManager::WaitForAll()
{
    BackgroundSystem.WaitForAll();
}

uint32_t AsyncJobManager::GetPendingCount() const
{
    return BackgroundSystem.GetPendingCount();
}