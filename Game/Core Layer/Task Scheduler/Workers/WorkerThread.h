#pragma once

#include <thread>
#include <atomic>

class PriorityJobQueue;

class WorkerThread
{
public:

    WorkerThread(
        PriorityJobQueue* InQueue
    );

    ~WorkerThread();

    void Start();

    void Stop();

private:

    void Run();

private:

    std::thread Thread;

    std::atomic<bool> Running;

    PriorityJobQueue* Queue;
};


