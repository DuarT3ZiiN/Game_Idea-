#pragma once

#include <cstdint>
#include <string>
#include <vector>

// PlayerSaveData — estado persistido do jogador.
//
// Melhorias em relação à versão anterior:
//   - ActiveVehicleID — veículo que estava em uso ao salvar
//   - SelectedEventID — evento selecionado no mapa (restaura cursor do jogador)
//   - DistrictID atual — posição no mundo para spawn após load

struct PlayerSaveData
{
    std::string PlayerName;

    uint64_t    Money         = 0;
    uint32_t    Reputation    = 0;
    uint32_t    Level         = 1;
    uint32_t    HeatLevel     = 0;

    uint64_t    ActiveVehicleID  = 0;  // veículo ativo ao salvar
    uint32_t    CurrentDistrictID = 0; // distrito onde o jogador estava

    std::vector<uint64_t> OwnedCars;
    std::vector<uint64_t> UnlockedEvents;
    std::vector<uint64_t> CompletedEvents;
};