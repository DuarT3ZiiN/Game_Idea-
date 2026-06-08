#include "ReplayCameraDirector.h"

void ReplayCameraDirector::UpdateCamera(
    float VehicleSpeed,
    bool CrashDetected,
    bool NearMiss
)
{
    if (CrashDetected)
    {
        CurrentMode =
            EReplayCameraMode::TV;

        return;
    }

    if (VehicleSpeed > 250.0f)
    {
        CurrentMode =
            EReplayCameraMode::
            Helicopter;

        return;
    }

    if (NearMiss)
    {
        CurrentMode =
            EReplayCameraMode::
            Cinematic;

        return;
    }

    CurrentMode =
        EReplayCameraMode::
        Chase;
}

EReplayCameraMode
ReplayCameraDirector::
GetCurrentMode() const
{
    return CurrentMode;
}

