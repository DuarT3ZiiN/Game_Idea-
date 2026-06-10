#pragma once

#include <cstdint>
#include <cmath>

#include "ReplicationSnapshot.h"

// SnapshotCompressor implementa delta compression entre snapshots.
//
// A versão anterior tinha Compress() e Decompress() vazios — inúteis.
//
// DeltaSnapshot carrega apenas os campos que mudaram em relação ao baseline.
// O receptor reconstrói o snapshot completo via Apply(baseline, delta).
//
// Threshold de posição: diferenças abaixo de 0.01 unidades não são enviadas
// — reduz tráfego em veículos parados ou em baixa velocidade.

static constexpr float DELTA_POSITION_EPSILON = 0.01f;
static constexpr float DELTA_ROTATION_EPSILON = 0.001f;
static constexpr float DELTA_SPEED_EPSILON    = 0.05f;

struct DeltaSnapshot
{
    TickID   Tick     = 0;
    EntityID Entity   = INVALID_ENTITY;

    bool bHasPosition = false;
    bool bHasRotation = false;
    bool bHasVelocity = false;

    float PositionX = 0.f;
    float PositionY = 0.f;
    float PositionZ = 0.f;

    float RotationX = 0.f;
    float RotationY = 0.f;
    float RotationZ = 0.f;
    float RotationW = 1.f;

    float Speed     = 0.f;
    float Throttle  = 0.f;
    float Steering  = 0.f;
};

class SnapshotCompressor
{
public:

    // Gera delta entre baseline e current — envia apenas o que mudou
    static DeltaSnapshot Compress(
        const ReplicationSnapshot& Baseline,
        const ReplicationSnapshot& Current
    );

    // Reconstrói snapshot completo aplicando delta sobre baseline
    static ReplicationSnapshot Decompress(
        const ReplicationSnapshot& Baseline,
        const DeltaSnapshot&       Delta
    );
};