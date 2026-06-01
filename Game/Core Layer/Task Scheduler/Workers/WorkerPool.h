#pragma once

#include <vector>
#include <memory>

#include "WorkerThread.h"

class WorkerPool
{
public:

    void Initialize(
        uint32_t WorkerCount,
        PriorityJobQueue* Queue
    );

    void Shutdown();

private:

    std::vector<
        std::unique_ptr<WorkerThread>
    > Workers;
};


