#pragma once

#include <vector>
#include <memory>

#include "WorkerThread.h"

class PriorityJobQueue;
class PerformanceMonitor;

class WorkerPool
{
public:

    void Initialize(
        uint32_t            WorkerCount,
        PriorityJobQueue*   Queue,
        PerformanceMonitor* Monitor = nullptr
    );

    void Shutdown();

    uint32_t GetWorkerCount() const;

private:

    std::vector<std::unique_ptr<WorkerThread>> Workers;
};