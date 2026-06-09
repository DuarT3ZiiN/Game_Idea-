#pragma once

#include <cstdint>

#include "ReplayTypes.h"
#include "TransformSnapshot.h"

// ReplayCamera representa uma câmera no modo replay.
//
// Melhorias em relação à versão anterior:
//   - TargetEntityID — câmera sabe qual veículo está seguindo
//   - CameraTransform — posição e rotação atual da câmera (para renderização)
//   - Update() — calcula CameraTransform baseado no modo e no estado do veículo

class ReplayCamera
{
public:

    void SetMode(EReplayCameraMode NewMode);
    void SetTarget(uint64_t EntityID);

    // Atualiza CameraTransform baseado no VehicleStateSnapshot atual
    void Update(const struct VehicleStateSnapshot& VehicleState);

    EReplayCameraMode     GetMode()            const { return Mode; }
    uint64_t             GetTargetEntityID()   const { return TargetEntityID; }
    const TransformSnapshot& GetCameraTransform() const { return CameraTransform; }

private:

    EReplayCameraMode Mode            = EReplayCameraMode::Chase;
    uint64_t          TargetEntityID  = 0;
    TransformSnapshot CameraTransform;
};