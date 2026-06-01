#pragma once

#include "PriorityJobQueue.h"
#include "WorkerPool.h"
#include "RuntimeBudgetManager.h"
#include "DependencyGraph.h"
#include "PerformanceMonitor.h"

class TaskScheduler
{
public:

    void Initialize(
        uint32_t WorkerCount
    );

    void Shutdown();

    void Submit(
        const Job& InJob
    );

private:

    PriorityJobQueue Queue;

    WorkerPool Workers;

    RuntimeBudgetManager BudgetManager;

    DependencyGraph Dependencies;

    PerformanceMonitor Profiler;
};

