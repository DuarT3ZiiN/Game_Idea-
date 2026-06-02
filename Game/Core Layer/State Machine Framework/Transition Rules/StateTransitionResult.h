#pragma once
 
#include <cstdint>
 
enum class EStateTransitionResult : uint8_t
{
    Success,            // Transição executada com sucesso
    AlreadyInState,     // Já estava no estado destino (não é erro)
    InvalidState,       // Estado destino é inválido (ex: Invalid)
    IllegalTransition,  // Transição não consta nas regras do Validator
    Blocked             // Condição de bloqueio (ex: Unpause sem estar Paused)
};
 