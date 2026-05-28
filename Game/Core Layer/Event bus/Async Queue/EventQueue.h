#pragma once

#include <queue>
#include <mutex>

#include "Event.h"

class EventQueue
{
public:

    void Push(const Event& InEvent);

    bool Pop(Event& OutEvent);

    bool IsEmpty() const;

private:

    std::queue<Event> Queue;

    mutable std::mutex Mutex;
};
