
#pragma once

#include <thread>
#include <atomic>

class AsyncJobQueue;

class AsyncWorker
{
public:

    explicit AsyncWorker(
        AsyncJobQueue* InQueue
    );

    ~AsyncWorker();

    void Start();

    void Stop();

private:

    void Run();

private:

    std::thread WorkerThread;

    std::atomic<bool> Running;

    AsyncJobQueue* Queue;
};

