#include "ReplayCamera.h"

void ReplayCamera::SetMode(
    EReplayCameraMode NewMode
)
{
    Mode = NewMode;
}

EReplayCameraMode
ReplayCamera::GetMode() const
{
    return Mode;
}