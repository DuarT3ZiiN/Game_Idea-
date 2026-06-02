#pragma once
 
#include <functional>
 
#include "GlobalStateContext.h"
#include "StateTransitionResult.h"
#include "StateValidator.h"
 
// GlobalStateMachine controla o estado macro do jogo.
//
// Melhorias em relação à versão anterior:
//   - Pause() / Unpause() — preserva estado pré-pause e restaura corretamente
//   - OnStateChanged callback — permite que EventBus, GlobalDirector e outros
//     sistemas reajam à mudança sem acoplamento direto
//   - IsInState() — consulta conveniente
//   - ChangeState retorna resultado tipado para logging e debug
 
using GlobalStateChangedCallback =
    std::function<void(EGlobalState /*From*/, EGlobalState /*To*/)>;
 
class GlobalStateMachine
{
public:
 
    GlobalStateMachine();
 
    // Muda para um novo estado, passando pela validação
    EStateTransitionResult ChangeState(EGlobalState NewState);
 
    // Pausa: guarda o estado atual e vai para Paused
    EStateTransitionResult Pause();
 
    // Unpause: restaura o estado pré-pause
    EStateTransitionResult Unpause();
 
    // Consulta
    EGlobalState GetCurrentState()  const;
    EGlobalState GetPreviousState() const;
    bool         IsInState(EGlobalState State) const;
    bool         IsPaused() const;
 
    // Callback opcional — chamado após toda transição bem-sucedida
    void SetOnStateChanged(GlobalStateChangedCallback Callback);
 
private:
 
    void ApplyTransition(EGlobalState NewState);
 
private:
 
    GlobalStateContext           Context;
    StateValidator               Validator;
    GlobalStateChangedCallback   OnStateChanged;
};
 