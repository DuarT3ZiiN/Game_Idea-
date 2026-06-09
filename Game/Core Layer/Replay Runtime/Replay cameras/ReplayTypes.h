#pragma once

#include <cstdint>

enum class EReplayState : uint8_t
{
    Recording,
    Playback,
    Paused,
    Scrubbing,
    Finished
};

enum class EReplayCameraMode : uint8_t
{
    Chase,
    Hood,
    Bumper,
    Cinematic,
    Helicopter,
    Orbit,
    TV
};