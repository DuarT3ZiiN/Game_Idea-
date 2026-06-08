
#pragma once

class ReplayCameraDirector
{
public:

    void UpdateCamera(
        float VehicleSpeed,
        bool CrashDetected,
        bool NearMiss
    );

    EReplayCameraMode
    GetCurrentMode() const;

private:

    EReplayCameraMode CurrentMode =
        EReplayCameraMode::Chase;
};

