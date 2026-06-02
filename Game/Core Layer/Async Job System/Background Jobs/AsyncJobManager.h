#pragma once

#include "BackgroundJobSystem.h"

class AsyncJobManager
{
public:

    void Initialize();

    void Shutdown();

    void Submit(
        const AsyncJob& Job
    );

private:

    BackgroundJobSystem BackgroundSystem;
};
