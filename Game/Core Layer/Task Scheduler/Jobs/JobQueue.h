#pragma once

#include <queue>
#include <mutex>

#include "Job.h"

class JobQueue
{
public:

    void Push(const Job& InJob);

    bool Pop(Job& OutJob);

    bool Empty() const;

private:

    std::queue<Job> Queue;

    mutable std::mutex Mutex;
};
