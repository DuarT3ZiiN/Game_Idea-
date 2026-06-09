#pragma once

#include "NetworkTypes.h"
#include "NetworkTransform.h"

// AuthoritativeState é o estado canônico vindo do servidor.
// Usado pelo ReconciliationRuntime para comparar com a predição do cliente.
//
// Melhoria em relação à versão anterior:
//   - Usa NetworkTransform do header compartilhado (sem redefinição)
//   - Speed incluído para threshold de reconciliação (erro de velocidade)

struct AuthoritativeState
{
    TickID           Tick      = INVALID_TICK;
    NetworkTransform Transform;
    float            Speed     = 0.f;
    float            Velocity  = 0.f;
};