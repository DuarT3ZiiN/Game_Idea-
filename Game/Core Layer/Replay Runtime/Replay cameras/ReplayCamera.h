#pragma once

class ReplayCamera
{
public:

    void SetMode(
        EReplayCameraMode Mode
    );

    EReplayCameraMode
    GetMode() const;

private:

    EReplayCameraMode Mode =
        EReplayCameraMode::Chase;
};

