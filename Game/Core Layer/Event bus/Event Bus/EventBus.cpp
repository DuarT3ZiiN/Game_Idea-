#include "EventBus.h"
 
#include <algorithm>
 
void EventBus::Subscribe(
    EventNameID          NameID,
    const EventListener& Listener
)
{
    Listeners[NameID].push_back(Listener);
}
 
void EventBus::Unsubscribe(
    EventNameID NameID,
    uint64_t    ListenerID
)
{
    auto It = Listeners.find(NameID);
 
    if (It == Listeners.end())
        return;
 
    auto& Array = It->second;
 
    Array.erase(
        std::remove_if(
            Array.begin(),
            Array.end(),
            [ListenerID](const EventListener& L)
            {
                return L.ListenerID == ListenerID;
            }
        ),
        Array.end()
    );
}
 
void EventBus::Publish(const Event& InEvent)
{
    switch (InEvent.Priority)
    {
        case EEventPriority::Critical:   Queue.PushCritical(InEvent);   break;
        case EEventPriority::High:       Queue.PushHigh(InEvent);       break;
        case EEventPriority::Normal:     Queue.PushNormal(InEvent);     break;
        case EEventPriority::Background: Queue.PushBackground(InEvent); break;
    }
}
 
void EventBus::PublishImmediate(const Event& InEvent)
{
    Dispatch(InEvent);
}
 
void EventBus::ProcessEvents()
{
    Event Current;
 
    while (Queue.PopNext(Current))
    {
        Dispatch(Current);
    }
}
 
void EventBus::Dispatch(const Event& InEvent)
{
    auto It = Listeners.find(InEvent.NameID);
 
    if (It == Listeners.end())
        return;
 
    // Cópia local do vetor — protege contra Unsubscribe dentro de um callback
    const std::vector<EventListener> LocalListeners = It->second;
 
    for (const EventListener& Listener : LocalListeners)
    {
        Listener.Callback(InEvent);
    }
}