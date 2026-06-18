#pragma once

#include <cstdint>

enum class EAudioAssetType : uint8_t
{
    Engine,
    Exhaust,
    Turbo,
    TireSquealing,  // drift/brake squeal (seção 2.1 Vehicle Simulation)
    ImpactSFX,      // colisões de veículo
    Music,
    Ambience,       // ambiente do distrito
    Radio,
    PoliceRadio,
    UI,
    Voice
};