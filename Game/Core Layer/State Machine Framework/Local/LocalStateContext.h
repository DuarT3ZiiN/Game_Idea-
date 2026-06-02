
#pragma once
 
#include <unordered_map>
#include <unordered_set>
#include <chrono>
 
#include "LocalStates.h"
 
// LocalStateContext mantém quais estados locais estão ativos
// e quando cada um foi ativado (para duração e timeout).
//
// Melhoria em relação à versão anterior:
//   - ActivationTime por estado — permite calcular duração
//     (ex: DriftChain score, PursuitCooldown timer)
 
struct LocalStateContext
{
    // Conjunto de estados ativos no momento
    std::unordered_set<ELocalState> ActiveStates;
 
    // Timestamp de ativação de cada estado ativo
    std::unordered_map<ELocalState, double> ActivationTime;
};
 