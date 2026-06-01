#pragma once

#include "JobQueue.h"

class PriorityJobQueue
{
public:

    void Push(const Job& InJob);

    bool Pop(Job& OutJob);

private:

    JobQueue CriticalQueue;
    JobQueue HighQueue;
    JobQueue NormalQueue;
    JobQueue LowQueue;
};