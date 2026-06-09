#pragma once

#include <vector>

#include "NetworkTypes.h"
#include "NetworkTransform.h"
#include "Entity.h"

struct ReplicationSnapshot
{
    TickID           Tick      = INVALID_TICK;
    EntityID         Entity    = INVALID_ENTITY;

    NetworkTransform Transform;

    float Velocity  = 0.f;
    float Steering  = 0.f;
    float Throttle  = 0.f;
    float Speed     = 0.f;
};