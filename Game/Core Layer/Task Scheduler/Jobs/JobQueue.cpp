#include "JobQueue.h"

void JobQueue::Push(
    const Job& InJob
)
{
    std::lock_guard<std::mutex> Lock(Mutex);

    Queue.push(InJob);
}

bool JobQueue::Pop(
    Job& OutJob
)
{
    std::lock_guard<std::mutex> Lock(Mutex);

    if (Queue.empty())
        return false;

    OutJob = Queue.front();

    Queue.pop();

    return true;
}

bool JobQueue::Empty() const
{
    std::lock_guard<std::mutex> Lock(Mutex);

    return Queue.empty();
}


