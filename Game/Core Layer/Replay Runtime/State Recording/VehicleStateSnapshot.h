#pragma once

#include <cstdint>

#include "TransformSnapshot.h"
#include "ReplayFrameID.h"

// VehicleStateSnapshot captura o estado completo de um veículo num frame.
//
// Melhorias em relação à versão anterior:
//   - NitroAmount: necessário para reproduzir visualmente o nitro no playback
//   - DriftAngle: estado do drift (seção 1.1.2.3 Drift Rules)
//   - WheelSlip[4]: slip de cada roda (para efeitos de partícula no replay)
//   - bHandbrake: estado do freio de mão
//   - Gear: marcha atual

struct VehicleStateSnapshot
{
    ReplayFrameID FrameID    = 0;
    uint64_t      VehicleID  = 0;

    TransformSnapshot Transform;

    float   Speed       = 0.f;
    float   RPM         = 0.f;
    int8_t  Gear        = 1;
    float   Damage      = 0.f;
    float   NitroAmount = 0.f;
    float   DriftAngle  = 0.f;
    bool    bHandbrake  = false;

    float   WheelSlip[4] = { 0.f, 0.f, 0.f, 0.f };
};