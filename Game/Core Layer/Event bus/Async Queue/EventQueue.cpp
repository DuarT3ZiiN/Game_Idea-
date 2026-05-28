#include "EventQueue.h"

void EventQueue::Push(const Event& InEvent)
{
    std::lock_guard<std::mutex> Lock(Mutex);

    Queue.push(InEvent);
}

bool EventQueue::Pop(Event& OutEvent)
{
    std::lock_guard<std::mutex> Lock(Mutex);

    if (Queue.empty())
        return false;

    OutEvent = Queue.front();

    Queue.pop();

    return true;
}

bool EventQueue::IsEmpty() const
{
    std::lock_guard<std::mutex> Lock(Mutex);

    return Queue.empty();
}

