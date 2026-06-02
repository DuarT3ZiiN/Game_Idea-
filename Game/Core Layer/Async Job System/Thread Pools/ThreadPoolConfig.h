#pragma once

struct ThreadPoolConfig
{
    uint32_t WorkerCount = 4;

    uint32_t MaxPendingJobs = 10000;
};
