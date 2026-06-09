#include "ReplayCamera.h"

#include "VehicleStateSnapshot.h"

void ReplayCamera::SetMode(EReplayCameraMode NewMode)
{
    Mode = NewMode;
}

void ReplayCamera::SetTarget(uint64_t EntityID)
{
    TargetEntityID = EntityID;
}

void ReplayCamera::Update(const VehicleStateSnapshot& VehicleState)
{
    // Posicionamento simples por modo — expandir com offsets configuráveis
    switch (Mode)
    {
        case EReplayCameraMode::Chase:
            // Atrás e acima do veículo
            CameraTransform.Position = {
                VehicleState.Transform.Position.X - 10.f,
                VehicleState.Transform.Position.Y + 4.f,
                VehicleState.Transform.Position.Z
            };
            break;

        case EReplayCameraMode::Hood:
            CameraTransform.Position = {
                VehicleState.Transform.Position.X + 1.5f,
                VehicleState.Transform.Position.Y + 1.2f,
                VehicleState.Transform.Position.Z
            };
            break;

        case EReplayCameraMode::Bumper:
            CameraTransform.Position = VehicleState.Transform.Position;
            break;

        case EReplayCameraMode::Helicopter:
            CameraTransform.Position = {
                VehicleState.Transform.Position.X,
                VehicleState.Transform.Position.Y + 60.f,
                VehicleState.Transform.Position.Z
            };
            break;

        default:
            CameraTransform.Position = VehicleState.Transform.Position;
            break;
    }

    CameraTransform.Rotation = VehicleState.Transform.Rotation;
}