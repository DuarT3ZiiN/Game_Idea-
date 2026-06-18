#pragma once

struct DriftConfig
{
    float MinimumAngle = 15.0f;

    float MaximumAngle = 65.0f;

    float AngleMultiplier = 1.0f;

    float SpeedMultiplier = 1.0f;

    float TransitionBonus = 500.0f;

    float NearMissBonus = 1000.0f;

    float WallPenalty = 0.50f;

    float ComboDecayTime = 2.0f;
};