#pragma once

#include <cstdint>

#include "ReplayFrameID.h"

// InputSnapshot captura o estado de input em um frame.
//
// Melhorias em relação à versão anterior:
//   - FrameID e Timestamp — associam o snapshot ao frame exato
//     (necessário para o ReconciliationRuntime replayer inputs na ordem certa)
//   - Gear: estado da marcha (seção 1.1.2.4 Drag Rules exige isso)

struct InputSnapshot
{
    ReplayFrameID FrameID   = 0;
    double        Timestamp = 0.0;

    float Steering  = 0.f;
    float Throttle  = 0.f;
    float Brake     = 0.f;

    bool  bHandbrake = false;
    bool  bNitro     = false;
    bool  bGearUp    = false;
    bool  bGearDown  = false;

    int8_t Gear     = 1;   // marcha atual (1-6, -1 = ré)
};