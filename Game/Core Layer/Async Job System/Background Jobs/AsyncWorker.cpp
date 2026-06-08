#include "AsyncWorker.h"
#include "AsyncJobQueue.h"

AsyncWorker::AsyncWorker(
    AsyncJobQueue* InQueue,
    AsyncJobQueue* InRetryQueue
)
    : Running(false)
    , Queue(InQueue)
    , RetryQueue(InRetryQueue ? InRetryQueue : InQueue)
{
}

AsyncWorker::~AsyncWorker()
{
    Stop();
}

void AsyncWorker::Start()
{
    Running     = true;
    WorkerThread = std::thread(&AsyncWorker::Run, this);
}

void AsyncWorker::Stop()
{
    Running = false;

    if (WorkerThread.joinable())
        WorkerThread.join();
}

void AsyncWorker::Run()
{
    while (Running)
    {
        AsyncJob Job;

        // Dorme até um job estar disponível ou shutdown ser sinalizado
        if (!Queue->WaitAndPop(Job))
            break;

        if (!Job.Execute)
            continue;

        // Marca como Running
        if (Job.State)
            Job.State->store(
                EAsyncJobState::Running,
                std::memory_order_release
            );

        bool bSuccess = false;

        try
        {
            Job.Execute();
            bSuccess = true;
        }
        catch (...)
        {
            bSuccess = false;
        }

        if (bSuccess)
        {
            if (Job.State)
                Job.State->store(
                    EAsyncJobState::Completed,
                    std::memory_order_release
                );

            if (Job.OnComplete)
                Job.OnComplete(Job.ID);
        }
        else
        {
            // Tenta retry se ainda há tentativas restantes
            if (Job.RetryCount < Job.MaxRetries)
            {
                ++Job.RetryCount;

                if (Job.State)
                    Job.State->store(
                        EAsyncJobState::Retrying,
                        std::memory_order_release
                    );

                RetryQueue->Push(Job);
            }
            else
            {
                if (Job.State)
                    Job.State->store(
                        EAsyncJobState::Failed,
                        std::memory_order_release
                    );

                if (Job.OnFailed)
                    Job.OnFailed(Job.ID);
            }
        }
    }
}