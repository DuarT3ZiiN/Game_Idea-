#pragma once

#include <unordered_map>
#include <vector>

#include "EventListener.h"
#include "AsyncEventQueue.h"

class EventBus
{
public:

    void Subscribe(
        const std::string& EventName,
        const EventListener& Listener
    );

    void Unsubscribe(
        const std::string& EventName,
        uint64_t ListenerID
    );

    void Publish(const Event& InEvent);

    void ProcessEvents();

private:

    void Dispatch(const Event& InEvent);

private:

    AsyncEventQueue Queue;

    std::unordered_map<
        std::string,
        std::vector<EventListener>
    > Listeners;
};

