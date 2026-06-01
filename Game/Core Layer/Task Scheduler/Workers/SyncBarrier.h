#pragma once

#include <mutex>
#include <condition_variable>

class SyncBarrier
{
public:

    explicit SyncBarrier(
        uint32_t Count
    );

    void Wait();

private:

    std::mutex Mutex;

    std::condition_variable CV;

    uint32_t Threshold;

    uint32_t Counter;
};
