#include "AsyncEventQueue.h"

void AsyncEventQueue::PushCritical(
    const Event& Event
)
{
    CriticalQueue.Push(Event);
}

void AsyncEventQueue::PushHigh(
    const Event& Event
)
{
    HighQueue.Push(Event);
}

void AsyncEventQueue::PushNormal(
    const Event& Event
)
{
    NormalQueue.Push(Event);
}

void AsyncEventQueue::PushBackground(
    const Event& Event
)
{
    BackgroundQueue.Push(Event);
}

bool AsyncEventQueue::PopNext(Event& OutEvent)
{
    if (CriticalQueue.Pop(OutEvent))
        return true;

    if (HighQueue.Pop(OutEvent))
        return true;

    if (NormalQueue.Pop(OutEvent))
        return true;

    if (BackgroundQueue.Pop(OutEvent))
        return true;

    return false;
}

