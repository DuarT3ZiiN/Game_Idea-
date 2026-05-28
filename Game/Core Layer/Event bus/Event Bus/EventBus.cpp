#include "EventBus.h"

void EventBus::Subscribe(
    const std::string& EventName,
    const EventListener& Listener
)
{
    Listeners[EventName].push_back(
        Listener
    );
}

void EventBus::Unsubscribe(
    const std::string& EventName,
    uint64_t ListenerID
)
{
    auto& ListenerArray =
        Listeners[EventName];

    ListenerArray.erase(
        std::remove_if(
            ListenerArray.begin(),
            ListenerArray.end(),
            [&](const EventListener& Listener)
            {
                return Listener.ListenerID
                    == ListenerID;
            }
        ),
        ListenerArray.end()
    );
}

void EventBus::Publish(const Event& InEvent)
{
    switch (InEvent.Priority)
    {
        case EEventPriority::Critical:
        {
            Queue.PushCritical(InEvent);
            break;
        }

        case EEventPriority::High:
        {
            Queue.PushHigh(InEvent);
            break;
        }

        case EEventPriority::Normal:
        {
            Queue.PushNormal(InEvent);
            break;
        }

        case EEventPriority::Background:
        {
            Queue.PushBackground(InEvent);
            break;
        }
    }
}

void EventBus::ProcessEvents()
{
    Event CurrentEvent;

    while (Queue.PopNext(CurrentEvent))
    {
        Dispatch(CurrentEvent);
    }
}

void EventBus::Dispatch(
    const Event& InEvent
)
{
    auto It =
        Listeners.find(InEvent.Name);

    if (It == Listeners.end())
        return;

    for (const EventListener& Listener :
        It->second)
    {
        Listener.Callback(InEvent);
    }
}