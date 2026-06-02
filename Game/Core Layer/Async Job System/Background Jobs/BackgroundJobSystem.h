#pragma once

#include "ThreadPool.h"

class BackgroundJobSystem
{
public:

    void Initialize();

    void Shutdown();

    void SubmitBackgroundJob(
        const AsyncJob& Job
    );

private:

    ThreadPool Pool;
};


