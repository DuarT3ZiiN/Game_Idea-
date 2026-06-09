#include "ReplayCameraDirector.h"

void ReplayCameraDirector::SetCamera(ReplayCamera* InCamera)
{
    Camera = InCamera;
}

void ReplayCameraDirector::UpdateCamera(
    const VehicleStateSnapshot& State
)
{
    // Crash detectado via Damage alto → câmera TV (cobertura dramática)
    if (State.Damage > 0.8f)
    {
        CurrentMode = EReplayCameraMode::TV;
    }
    // Alta velocidade → helicoptero
    else if (State.Speed > HELICOPTER_SPEED_THRESHOLD)
    {
        CurrentMode = EReplayCameraMode::Helicopter;
    }
    // Drift ativo → câmera cinematográfica lateral
    else if (State.DriftAngle > DRIFT_ANGLE_THRESHOLD)
    {
        CurrentMode = EReplayCameraMode::Cinematic;
    }
    // Nitro ativo → câmera capô para sensação de velocidade
    else if (State.NitroAmount > 0.f && State.NitroAmount < 100.f)
    {
        CurrentMode = EReplayCameraMode::Hood;
    }
    else
    {
        CurrentMode = EReplayCameraMode::Chase;
    }

    if (Camera)
    {
        Camera->SetMode(CurrentMode);
        Camera->Update(State);
    }
}

EReplayCameraMode ReplayCameraDirector::GetCurrentMode() const
{
    return CurrentMode;
}