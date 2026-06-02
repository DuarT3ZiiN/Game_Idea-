#pragma once

#include <vector>
#include <memory>

#include "AsyncWorker.h"
#include "ThreadPoolConfig.h"

class ThreadPool
{
public:

    void Initialize(
        const ThreadPoolConfig& Config
    );

    void Shutdown();

    void Submit(
        const AsyncJob& Job
    );

private:

    ThreadPoolConfig Settings;

    AsyncJobQueue Queue;

    std::vector<
        std::unique_ptr<AsyncWorker>
    > Workers;
};
