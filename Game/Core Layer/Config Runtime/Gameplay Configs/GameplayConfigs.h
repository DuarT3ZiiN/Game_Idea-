#pragma once

struct GameplayConfig
{
    float NitroMultiplier = 1.0f;

    float SlipstreamBonus = 1.0f;

    float CrashSpeedThreshold = 90.0f;

    float DraftingDistance = 15.0f;

    float TrafficDensityMultiplier = 1.0f;

    bool EnablePoliceInSprint = true;

    bool EnablePoliceInCircuit = false;

    bool EnableTrafficInEvents = true;
};