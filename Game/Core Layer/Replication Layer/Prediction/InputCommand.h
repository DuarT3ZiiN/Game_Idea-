#pragma once

#include <cstdint>

#include "NetworkTypes.h"

struct InputCommand
{
    TickID Tick      = INVALID_TICK;

    float  Steering  = 0.f;
    float  Throttle  = 0.f;
    float  Brake     = 0.f;

    bool   bHandbrake = false;
    bool   bNitro     = false;

    int8_t Gear      = 1;
};