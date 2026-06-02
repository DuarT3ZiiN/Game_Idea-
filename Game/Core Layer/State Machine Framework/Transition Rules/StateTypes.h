#pragma once
 
#include <cstdint>
 
// Escopo de uma máquina de estados — diferencia Global (exclusiva)
// de Local (multi-estado simultâneo).
 
enum class EStateMachineScope : uint8_t
{
    Global, // Um estado ativo por vez (GlobalStateMachine)
    Local   // Múltiplos estados simultâneos (LocalStateMachine)
};
 