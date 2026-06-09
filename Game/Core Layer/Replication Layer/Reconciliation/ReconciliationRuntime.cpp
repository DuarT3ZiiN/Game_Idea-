#include "ReconciliationRuntime.h"

void ReconciliationRuntime::Initialize(ClientPrediction* InPrediction)
{
    Prediction = InPrediction;
}

void ReconciliationRuntime::ReceiveServerState(
    const AuthoritativeState& ServerState
)
{
    if (!Prediction)
        return;

    // Só reconcilia se o erro exceder o threshold
    if (!Prediction->NeedsReconciliation(ServerState))
    {
        // Mesmo sem corrigir posição, libera inputs confirmados do buffer
        Prediction->GetBuffer().AcknowledgeUpTo(ServerState.Tick);
        return;
    }

    Rollback(ServerState);
    ReplayInputs(ServerState.Tick);

    Prediction->GetBuffer().AcknowledgeUpTo(ServerState.Tick);
}

void ReconciliationRuntime::Rollback(const AuthoritativeState& ServerState)
{
    // TODO: restaurar TransformComponent e VelocityComponent da entidade
    // para os valores de ServerState.Transform e ServerState.Speed
    // Será implementado junto com StateReplicationSystem (acesso ao ECS)
    (void)ServerState;
}

void ReconciliationRuntime::ReplayInputs(TickID FromTick)
{
    if (!Prediction)
        return;

    // Re-aplica todos os inputs posteriores ao tick confirmado
    for (const auto& Cmd : Prediction->GetBuffer().GetCommands())
    {
        if (Cmd.Tick <= FromTick)
            continue;

        Prediction->PredictMovement(Cmd);
    }
}