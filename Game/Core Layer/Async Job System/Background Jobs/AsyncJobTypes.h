#pragma once

#include <cstdint>

enum class EAsyncJobType : uint8_t
{
    Background,
    Streaming,
    Telemetry,
    SaveGame,
    Replay,
    Analytics,
    AI,
    Navigation
};

