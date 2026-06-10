#include "SnapshotCompression.h"

DeltaSnapshot SnapshotCompressor::Compress(
    const ReplicationSnapshot& Baseline,
    const ReplicationSnapshot& Current
)
{
    DeltaSnapshot Delta;
    Delta.Tick   = Current.Tick;
    Delta.Entity = Current.Entity;

    // Posição
    const float DPX = fabsf(Current.Transform.PositionX - Baseline.Transform.PositionX);
    const float DPY = fabsf(Current.Transform.PositionY - Baseline.Transform.PositionY);
    const float DPZ = fabsf(Current.Transform.PositionZ - Baseline.Transform.PositionZ);

    if (DPX > DELTA_POSITION_EPSILON
     || DPY > DELTA_POSITION_EPSILON
     || DPZ > DELTA_POSITION_EPSILON)
    {
        Delta.bHasPosition = true;
        Delta.PositionX    = Current.Transform.PositionX;
        Delta.PositionY    = Current.Transform.PositionY;
        Delta.PositionZ    = Current.Transform.PositionZ;
    }

    // Rotação
    const float DRX = fabsf(Current.Transform.RotationX - Baseline.Transform.RotationX);
    const float DRY = fabsf(Current.Transform.RotationY - Baseline.Transform.RotationY);
    const float DRZ = fabsf(Current.Transform.RotationZ - Baseline.Transform.RotationZ);
    const float DRW = fabsf(Current.Transform.RotationW - Baseline.Transform.RotationW);

    if (DRX > DELTA_ROTATION_EPSILON
     || DRY > DELTA_ROTATION_EPSILON
     || DRZ > DELTA_ROTATION_EPSILON
     || DRW > DELTA_ROTATION_EPSILON)
    {
        Delta.bHasRotation = true;
        Delta.RotationX    = Current.Transform.RotationX;
        Delta.RotationY    = Current.Transform.RotationY;
        Delta.RotationZ    = Current.Transform.RotationZ;
        Delta.RotationW    = Current.Transform.RotationW;
    }

    // Velocidade / controles
    if (fabsf(Current.Speed    - Baseline.Speed)    > DELTA_SPEED_EPSILON
     || fabsf(Current.Throttle - Baseline.Throttle) > DELTA_SPEED_EPSILON
     || fabsf(Current.Steering - Baseline.Steering) > DELTA_SPEED_EPSILON)
    {
        Delta.bHasVelocity = true;
        Delta.Speed        = Current.Speed;
        Delta.Throttle     = Current.Throttle;
        Delta.Steering     = Current.Steering;
    }

    return Delta;
}

ReplicationSnapshot SnapshotCompressor::Decompress(
    const ReplicationSnapshot& Baseline,
    const DeltaSnapshot&       Delta
)
{
    ReplicationSnapshot Result = Baseline;
    Result.Tick   = Delta.Tick;
    Result.Entity = Delta.Entity;

    if (Delta.bHasPosition)
    {
        Result.Transform.PositionX = Delta.PositionX;
        Result.Transform.PositionY = Delta.PositionY;
        Result.Transform.PositionZ = Delta.PositionZ;
    }

    if (Delta.bHasRotation)
    {
        Result.Transform.RotationX = Delta.RotationX;
        Result.Transform.RotationY = Delta.RotationY;
        Result.Transform.RotationZ = Delta.RotationZ;
        Result.Transform.RotationW = Delta.RotationW;
    }

    if (Delta.bHasVelocity)
    {
        Result.Speed    = Delta.Speed;
        Result.Throttle = Delta.Throttle;
        Result.Steering = Delta.Steering;
    }

    return Result;
}