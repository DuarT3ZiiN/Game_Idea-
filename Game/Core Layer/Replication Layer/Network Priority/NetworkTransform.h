#pragma once

// NetworkTransform é shared entre ReplicationSnapshot e AuthoritativeState.
// Extraído para evitar redefinição em múltiplos headers.

struct NetworkTransform
{
    float PositionX  = 0.f;
    float PositionY  = 0.f;
    float PositionZ  = 0.f;

    float RotationX  = 0.f;
    float RotationY  = 0.f;
    float RotationZ  = 0.f;
    float RotationW  = 1.f;
};