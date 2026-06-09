#pragma once

#include "PredictionBuffer.h"
#include "AuthoritativeState.h"

// ClientPrediction simula movimento localmente antes da confirmação do servidor.
//
// Melhorias em relação à versão anterior:
//   - PredictedState mantido internamente — ReconciliationRuntime compara
//     PredictedState vs AuthoritativeState para decidir se precisa corrigir
//   - NeedsReconciliation() — threshold configurável de erro de posição
//   - PredictionBuffer integrado aqui (não no ReconciliationRuntime)

static constexpr float RECONCILIATION_POSITION_THRESHOLD = 0.5f; // metros

class ClientPrediction
{
public:

    void PredictMovement(const InputCommand& Input);

    void RecordInput(const InputCommand& Input);

    // Verifica se o erro em relação ao estado autoritativo excede o threshold
    bool NeedsReconciliation(const AuthoritativeState& ServerState) const;

    const PredictionBuffer& GetBuffer() const { return Buffer; }
    PredictionBuffer&       GetBuffer()       { return Buffer; }

private:

    PredictionBuffer Buffer;
    NetworkTransform PredictedTransform;
    float            PredictedSpeed = 0.f;
};