#pragma once

#include "EventQueue.h"

class AsyncEventQueue
{
public:

    void PushCritical(const Event& Event);

    void PushHigh(const Event& Event);

    void PushNormal(const Event& Event);

    void PushBackground(const Event& Event);

    bool PopNext(Event& OutEvent);

private:

    EventQueue CriticalQueue;

    EventQueue HighQueue;

    EventQueue NormalQueue;

    EventQueue BackgroundQueue;
};

