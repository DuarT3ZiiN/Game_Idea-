#pragma once
 
#include <unordered_map>
#include <vector>
 
#include "EventListener.h"
#include "AsyncEventQueue.h"
 
// EventBus melhorado:
//   - Chave do mapa é EventNameID (uint32_t hash) — sem alocação de string
//   - PublishImmediate() despacha Critical sem enfileirar (ex: OnPlayerCrash)
//   - Proteção contra modificação do mapa durante o Dispatch (safe iteration)
 
class EventBus
{
public:
 
    void Subscribe(
        EventNameID          NameID,
        const EventListener& Listener
    );
 
    void Unsubscribe(
        EventNameID NameID,
        uint64_t    ListenerID
    );
 
    // Enfileira o evento na fila de prioridade correspondente
    void Publish(const Event& InEvent);
 
    // Despacha imediatamente sem enfileirar — use apenas para Critical
    void PublishImmediate(const Event& InEvent);
 
    // Processa todos os eventos enfileirados (chame uma vez por frame)
    void ProcessEvents();
 
private:
 
    void Dispatch(const Event& InEvent);
 
private:
 
    AsyncEventQueue Queue;
 
    // EventNameID → listeners registrados
    std::unordered_map<
        EventNameID,
        std::vector<EventListener>
    > Listeners;
};
 