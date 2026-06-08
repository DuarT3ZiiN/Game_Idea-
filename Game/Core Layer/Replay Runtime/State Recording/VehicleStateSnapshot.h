#pragma once

struct VehicleStateSnapshot
{
    uint64_t VehicleID = 0;

    TransformSnapshot Transform;

    float Speed = 0.0f;

    float RPM = 0.0f;

    int Gear = 0;

    float Damage = 0.0f;
};