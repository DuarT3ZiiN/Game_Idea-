#pragma once

#include "ReplayCamera.h"
#include "VehicleStateSnapshot.h"

// ReplayCameraDirector decide automaticamente o melhor modo de câmera
// baseado no estado do veículo no frame atual.
//
// Melhorias em relação à versão anterior:
//   - UpdateCamera recebe VehicleStateSnapshot em vez de floats soltos —
//     agora pode reagir a DriftAngle, NitroAmount, Gear, etc.
//   - Mantém referência à ReplayCamera que controla
//   - Thresholds como constantes nomeadas para fácil tuning

class ReplayCameraDirector
{
public:

    void SetCamera(ReplayCamera* InCamera);

    void UpdateCamera(const VehicleStateSnapshot& State);

    EReplayCameraMode GetCurrentMode() const;

private:

    static constexpr float HELICOPTER_SPEED_THRESHOLD = 250.f;
    static constexpr float DRIFT_ANGLE_THRESHOLD      = 20.f;

    ReplayCamera*     Camera      = nullptr;
    EReplayCameraMode CurrentMode = EReplayCameraMode::Chase;
};