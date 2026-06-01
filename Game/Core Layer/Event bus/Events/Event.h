#pragma once
 
#include <cstdint>
#include <string_view>
 
#include "EventID.h"
#include "EventTypes.h"
#include "Entity.h"
 
// EventNameID é um hash de 32 bits do nome do evento.
// Substitui std::string no hot path do bus — sem alocação heap,
// comparação por inteiro ao invés de comparação de string.
//
// Use EventNames::Hash() para gerar o ID a partir de um literal.
 
using EventNameID = uint32_t;
 
namespace EventNames
{
    // FNV-1a 32-bit — determinístico e rápido para strings curtas
    constexpr EventNameID Hash(std::string_view Name)
    {
        uint32_t H = 2166136261u;
        for (char C : Name)
        {
            H ^= static_cast<uint8_t>(C);
            H *= 16777619u;
        }
        return H;
    }
 
    // Nomes canônicos do projeto (seção 1.1.1.6 do README)
    static constexpr EventNameID OnRaceStart       = Hash("OnRaceStart");
    static constexpr EventNameID OnCheckpointReached = Hash("OnCheckpointReached");
    static constexpr EventNameID OnPlayerCrash     = Hash("OnPlayerCrash");
    static constexpr EventNameID OnPursuitBegin    = Hash("OnPursuitBegin");
    static constexpr EventNameID OnPursuitEscaped  = Hash("OnPursuitEscaped");
    static constexpr EventNameID OnFinalLap        = Hash("OnFinalLap");
    static constexpr EventNameID OnRaceFinished    = Hash("OnRaceFinished");
    static constexpr EventNameID OnPoliceJoined    = Hash("OnPoliceJoined");
    static constexpr EventNameID OnDistrictLoaded  = Hash("OnDistrictLoaded");
}
 
struct Event
{
    EventID       ID           = 0;
    EventNameID   NameID       = 0;
 
    EEventType    Type         = EEventType::Global;
    EEventPriority Priority    = EEventPriority::Normal;
 
    EntityID      SourceEntity = INVALID_ENTITY;
 
    double        Timestamp    = 0.0;
 
    bool          bReplicated  = false;
    bool          bReplayable  = true;
 
    // Payload genérico — dados opcionais do evento (ex: dano, velocidade)
    // Sistemas que precisam de dados tipados devem criar structs derivadas
    // e passar via ponteiro/índice no payload.
    uint64_t      Payload      = 0;
};
 