#pragma once

#include <vector>

struct NetworkTransform
{
    float PositionX;
    float PositionY;
    float PositionZ;

    float RotationX;
    float RotationY;
    float RotationZ;
    float RotationW;
};

struct ReplicationSnapshot
{
    TickID Tick;

    EntityID Entity;

    NetworkTransform Transform;

    float Velocity;

    float Steering;

    float Throttle;
};
