#include "AsyncWorker.h"
#include "AsyncJobQueue.h"

AsyncWorker::AsyncWorker(
    AsyncJobQueue* InQueue
)
{
    Queue = InQueue;

    Running = false;
}

AsyncWorker::~AsyncWorker()
{
    Stop();
}

void AsyncWorker::Start()
{
    Running = true;

    WorkerThread =
        std::thread(
            &AsyncWorker::Run,
            this
        );
}

void AsyncWorker::Stop()
{
    Running = false;

    if (WorkerThread.joinable())
    {
        WorkerThread.join();
    }
}

void AsyncWorker::Run()
{
    while (Running)
    {
        AsyncJob Job;

        if (!Queue->Pop(Job))
            continue;

        Job.State =
            EAsyncJobState::Running;

        try
        {
            Job.Execute();

            Job.State =
                EAsyncJobState::Completed;
        }
        catch (...)
        {
            Job.State =
                EAsyncJobState::Failed;
        }
    }
}
