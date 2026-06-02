#pragma once
 
#include <unordered_set>
#include <cstdint>
 
#include "GlobalStates.h"
 
// StateValidator verifica se uma transição entre dois EGlobalState é legal.
//
// Melhoria em relação à versão anterior:
//   - Usa unordered_set com chave hash em vez de vetor linear
//     → IsTransitionValid é O(1) em vez de O(n)
//   - RegisterTransition() público permite que RuntimeStateCoordinator
//     estenda as regras sem recompilar o Validator
 
struct TransitionKey
{
    EGlobalState From;
    EGlobalState To;
 
    bool operator==(const TransitionKey& Other) const
    {
        return From == Other.From && To == Other.To;
    }
};
 
struct TransitionKeyHash
{
    std::size_t operator()(const TransitionKey& K) const noexcept
    {
        // Combina os dois uint8 em um único size_t
        return (static_cast<std::size_t>(K.From) << 8)
             | static_cast<std::size_t>(K.To);
    }
};
 
class StateValidator
{
public:
 
    StateValidator();
 
    bool IsTransitionValid(EGlobalState From, EGlobalState To) const;
 
    // Permite registrar transições extras em runtime (ex: mods, debug)
    void RegisterTransition(EGlobalState From, EGlobalState To);
 
private:
 
    std::unordered_set<TransitionKey, TransitionKeyHash> ValidTransitions;
};
 