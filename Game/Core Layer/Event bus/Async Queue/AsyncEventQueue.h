#pragma once
 
#include "EventQueue.h"
 
// AsyncEventQueue mantém 4 filas separadas por prioridade.
// PopNext sempre drena Critical antes de High, High antes de Normal, etc.
// Cada fila é um ring buffer independente e thread-safe.
 
class AsyncEventQueue
{
public:
 
    bool PushCritical  (const Event& InEvent) { return CriticalQueue.Push(InEvent);   }
    bool PushHigh      (const Event& InEvent) { return HighQueue.Push(InEvent);       }
    bool PushNormal    (const Event& InEvent) { return NormalQueue.Push(InEvent);     }
    bool PushBackground(const Event& InEvent) { return BackgroundQueue.Push(InEvent); }
 
    bool PopNext(Event& OutEvent)
    {
        if (CriticalQueue.Pop(OutEvent))   return true;
        if (HighQueue.Pop(OutEvent))       return true;
        if (NormalQueue.Pop(OutEvent))     return true;
        if (BackgroundQueue.Pop(OutEvent)) return true;
        return false;
    }
 
    bool IsEmpty() const
    {
        return CriticalQueue.IsEmpty()
            && HighQueue.IsEmpty()
            && NormalQueue.IsEmpty()
            && BackgroundQueue.IsEmpty();
    }
 
private:
 
    EventQueue CriticalQueue;
    EventQueue HighQueue;
    EventQueue NormalQueue;
    EventQueue BackgroundQueue;
};
 