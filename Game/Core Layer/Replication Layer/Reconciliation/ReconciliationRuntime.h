#pragma once

#include "ClientPrediction.h"

// ReconciliationRuntime corrige o estado do cliente quando o servidor
// confirma uma posição diferente da predição local.
//
// Fluxo de reconciliação (seção 3.8 do README):
//   1. ReceiveServerState()  — compara com predição via NeedsReconciliation()
//   2. Rollback()            — restaura o estado no tick autoritativo
//   3. ReplayInputs()        — re-aplica inputs do buffer a partir desse tick
//   4. Estado fica consistente com o servidor
//
// Melhoria em relação à versão anterior:
//   - Fluxo implementado em métodos separados e documentados
//   - Usa ClientPrediction.GetBuffer().AcknowledgeUpTo() para limpar
//     inputs confirmados após reconciliação

class ReconciliationRuntime
{
public:

    // Recebe a referência à ClientPrediction para acessar o buffer e NeedsReconciliation
    void Initialize(ClientPrediction* InPrediction);

    // Ponto de entrada: chamado quando o servidor envia estado autoritativo
    void ReceiveServerState(const AuthoritativeState& ServerState);

private:

    void Rollback(const AuthoritativeState& ServerState);
    void ReplayInputs(TickID FromTick);

private:

    ClientPrediction* Prediction = nullptr;
};