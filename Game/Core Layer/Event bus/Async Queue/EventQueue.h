#pragma once
 
#include <array>
#include <mutex>
#include <cstdint>
 
#include "Event.h"
 
// EventQueue implementada como ring buffer de tamanho fixo.
// Substitui std::queue (que aloca heap) por array estático contíguo.
// Capacidade padrão: 256 eventos por fila de prioridade.
// Se a fila encher, Push retorna false e o evento é descartado
// (situação que nunca deve ocorrer em operação normal).
 
static constexpr uint32_t EVENT_QUEUE_CAPACITY = 256;
 
class EventQueue
{
public:
 
    EventQueue()
        : Head(0)
        , Tail(0)
        , Size(0)
    {
    }
 
    bool Push(const Event& InEvent)
    {
        std::lock_guard<std::mutex> Lock(Mutex);
 
        if (Size >= EVENT_QUEUE_CAPACITY)
            return false;   // Fila cheia — não descarta silenciosamente em debug
 
        Buffer[Tail] = InEvent;
        Tail = (Tail + 1) % EVENT_QUEUE_CAPACITY;
        ++Size;
 
        return true;
    }
 
    bool Pop(Event& OutEvent)
    {
        std::lock_guard<std::mutex> Lock(Mutex);
 
        if (Size == 0)
            return false;
 
        OutEvent = Buffer[Head];
        Head = (Head + 1) % EVENT_QUEUE_CAPACITY;
        --Size;
 
        return true;
    }
 
    bool IsEmpty() const
    {
        std::lock_guard<std::mutex> Lock(Mutex);
        return Size == 0;
    }
 
    uint32_t GetSize() const
    {
        std::lock_guard<std::mutex> Lock(Mutex);
        return Size;
    }
 
private:
 
    mutable std::mutex                          Mutex;
    std::array<Event, EVENT_QUEUE_CAPACITY>     Buffer;
    uint32_t                                    Head;
    uint32_t                                    Tail;
    uint32_t                                    Size;
};