#pragma once

#include <queue>
#include <mutex>

#include "AsyncJob.h"

class AsyncJobQueue
{
public:

    void Push(
        const AsyncJob& Job
    );

    bool Pop(
        AsyncJob& Job
    );

    bool Empty() const;

private:

    std::queue<AsyncJob> Queue;

    mutable std::mutex Mutex;
};


