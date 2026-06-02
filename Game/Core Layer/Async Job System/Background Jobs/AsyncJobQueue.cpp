#include "AsyncJobQueue.h"

void AsyncJobQueue::Push(
    const AsyncJob& Job
)
{
    std::lock_guard<
        std::mutex
    > Lock(Mutex);

    Queue.push(Job);
}

bool AsyncJobQueue::Pop(
    AsyncJob& Job
)
{
    std::lock_guard<
        std::mutex
    > Lock(Mutex);

    if (Queue.empty())
        return false;

    Job = Queue.front();

    Queue.pop();

    return true;
}

bool AsyncJobQueue::Empty() const
{
    std::lock_guard<
        std::mutex
    > Lock(Mutex);

    return Queue.empty();
}

