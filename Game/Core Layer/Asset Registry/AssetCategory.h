#pragma once

#include <cstdint>

enum class EAssetCategory : uint8_t
{
    Vehicle,
    World,
    Audio,
    VFX,      // efeitos de partícula, explosões, fumaça de pneu
    UI,       // texturas e layouts de HUD
    Script,   // dados de eventos, missões, diálogos
    Replay    // arquivos .replay
};