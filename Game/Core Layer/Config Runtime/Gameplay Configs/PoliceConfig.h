#pragma once

struct PoliceConfig
{
    uint32_t MaxHeatLevel = 10;

    uint32_t MaxUnits = 20;

    float EscalationMultiplier = 1.0f;

    float SearchTimeout = 45.0f;

    float RoadblockChance = 0.35f;
};
