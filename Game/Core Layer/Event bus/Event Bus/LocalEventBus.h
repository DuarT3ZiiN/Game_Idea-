#pragma once
 
#include <unordered_map>
 
#include "EventBus.h"
 
// LocalEventBus mantém um EventBus por RegionID (distrito).
// Permite que eventos de corrida/perseguição sejam isolados por região,
// evitando que listeners de um distrito processem eventos de outro.
 
class LocalEventBus
{
public:
 
    void RegisterRegion(uint32_t RegionID);
 
    void UnregisterRegion(uint32_t RegionID);
 
    bool HasRegion(uint32_t RegionID) const;
 
    // Retorna o bus da região. Asserta se a região não existir.
    EventBus& GetRegionBus(uint32_t RegionID);
 
    // Processa todos os buses de todas as regiões ativas
    void ProcessAll();
 
private:
 
    std::unordered_map<uint32_t, EventBus> RegionalBuses;
};
 