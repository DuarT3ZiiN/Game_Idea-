#include "ClientPrediction.h"

#include <cmath>

void ClientPrediction::PredictMovement(const InputCommand& Input)
{
    // TODO: simular física do veículo localmente
    // - aplicar throttle/steering ao PredictedTransform
    // - atualizar PredictedSpeed
    // Por ora stub — será implementado junto com o Vehicle Simulation (2.1)

    RecordInput(Input);
}

void ClientPrediction::RecordInput(const InputCommand& Input)
{
    Buffer.Push(Input);
}

bool ClientPrediction::NeedsReconciliation(
    const AuthoritativeState& ServerState
) const
{
    const float DX = PredictedTransform.PositionX - ServerState.Transform.PositionX;
    const float DY = PredictedTransform.PositionY - ServerState.Transform.PositionY;
    const float DZ = PredictedTransform.PositionZ - ServerState.Transform.PositionZ;

    const float Distance = sqrtf(DX * DX + DY * DY + DZ * DZ);

    return Distance > RECONCILIATION_POSITION_THRESHOLD;
}