#pragma once

#include <cstdint>
#include <vector>

struct DistrictState
{
    uint32_t DistrictID  = 0;
    bool     bIsUnlocked = false;
    bool     bIsLoaded   = false; // estava carregado ao salvar (streaming hint)
};

// RivalState — progresso de um rival (seção 1.3 do README)
struct RivalState
{
    uint32_t RivalID         = 0;
    uint32_t Reputation      = 0;
    bool     bDefeated       = false;
    bool     bIntroCompleted = false;
};

struct WorldSaveData
{
    uint64_t WorldSeed   = 0;
    uint64_t WorldTimeMS = 0; // tempo do mundo em milissegundos (ciclo dia/noite)

    std::vector<DistrictState> Districts;
    std::vector<RivalState>    Rivals;
};