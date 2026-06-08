#include "AsyncJobQueue.h"

AsyncJobQueue::AsyncJobQueue()
    : Head(0)
    , Tail(0)
    , Size(0)
    , bShutdown(false)
{
}

bool AsyncJobQueue::Push(const AsyncJob& Job)
{
    std::lock_guard<std::mutex> Lock(Mutex);

    if (Size >= ASYNC_QUEUE_CAPACITY)
        return false;

    Buffer[Tail] = Job;
    Tail = (Tail + 1) % ASYNC_QUEUE_CAPACITY;
    ++Size;

    CV.notify_one();

    return true;
}

bool AsyncJobQueue::WaitAndPop(AsyncJob& OutJob)
{
    std::unique_lock<std::mutex> Lock(Mutex);

    CV.wait(Lock, [this]
    {
        return Size > 0 || bShutdown;
    });

    if (bShutdown && Size == 0)
        return false;

    OutJob = Buffer[Head];
    Head   = (Head + 1) % ASYNC_QUEUE_CAPACITY;
    --Size;

    return true;
}

bool AsyncJobQueue::TryPop(AsyncJob& OutJob)
{
    std::lock_guard<std::mutex> Lock(Mutex);

    if (Size == 0)
        return false;

    OutJob = Buffer[Head];
    Head   = (Head + 1) % ASYNC_QUEUE_CAPACITY;
    --Size;

    return true;
}

bool AsyncJobQueue::Empty() const
{
    std::lock_guard<std::mutex> Lock(Mutex);
    return Size == 0;
}

uint32_t AsyncJobQueue::GetSize() const
{
    std::lock_guard<std::mutex> Lock(Mutex);
    return Size;
}

void AsyncJobQueue::SignalShutdown()
{
    {
        std::lock_guard<std::mutex> Lock(Mutex);
        bShutdown = true;
    }
    CV.notify_all();
}