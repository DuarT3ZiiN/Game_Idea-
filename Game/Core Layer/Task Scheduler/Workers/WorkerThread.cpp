#include "WorkerThread.h"
#include "PriorityJobQueue.h"

WorkerThread::WorkerThread(
    PriorityJobQueue* InQueue
)
{
    Queue = InQueue;

    Running = false;
}

WorkerThread::~WorkerThread()
{
    Stop();
}

void WorkerThread::Start()
{
    Running = true;

    Thread =
        std::thread(
            &WorkerThread::Run,
            this
        );
}

void WorkerThread::Stop()
{
    Running = false;

    if (Thread.joinable())
    {
        Thread.join();
    }
}

void WorkerThread::Run()
{
    while (Running)
    {
        Job CurrentJob;

        if (Queue->Pop(CurrentJob))
        {
            CurrentJob.Execute();
        }
    }
}


