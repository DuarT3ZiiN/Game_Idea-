#pragma once

struct PerformanceMetrics
{
    float FrameTimeMS = 0.0f;

    float GameThreadMS = 0.0f;

    float RenderThreadMS = 0.0f;

    float PhysicsThreadMS = 0.0f;

    float NetworkThreadMS = 0.0f;

    uint64_t DrawCalls = 0;

    uint64_t EntityCount = 0;

    uint64_t ActiveVehicles = 0;

    uint64_t ActivePoliceUnits = 0;

    uint64_t ActiveTrafficVehicles = 0;

    float FPS = 0.0f;
};