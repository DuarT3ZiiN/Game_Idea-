#include "JobQueue.h"

bool JobQueue::Push(const Job& InJob)
{
    std::lock_guard<std::mutex> Lock(Mutex);

    if (Size >= JOB_QUEUE_CAPACITY)
        return false; // fila cheia

    Buffer[Tail] = InJob;
    Tail = (Tail + 1) % JOB_QUEUE_CAPACITY;
    ++Size;

    CV.notify_one(); // acorda um worker que esteja em WaitAndPop
    return true;
}

bool JobQueue::WaitAndPop(Job& OutJob)
{
    std::unique_lock<std::mutex> Lock(Mutex);

    CV.wait(Lock, [this]
    {
        return Size > 0 || bShutdown;
    });

    if (bShutdown && Size == 0)
        return false;

    OutJob = Buffer[Head];
    Head   = (Head + 1) % JOB_QUEUE_CAPACITY;
    --Size;

    return true;
}

bool JobQueue::TryPop(Job& OutJob)
{
    std::lock_guard<std::mutex> Lock(Mutex);

    if (Size == 0)
        return false;

    OutJob = Buffer[Head];
    Head   = (Head + 1) % JOB_QUEUE_CAPACITY;
    --Size;

    return true;
}

bool JobQueue::Empty() const
{
    std::lock_guard<std::mutex> Lock(Mutex);
    return Size == 0;
}

uint32_t JobQueue::GetSize() const
{
    std::lock_guard<std::mutex> Lock(Mutex);
    return Size;
}

void JobQueue::SignalShutdown()
{
    {
        std::lock_guard<std::mutex> Lock(Mutex);
        bShutdown = true;
    }
    CV.notify_all();
}