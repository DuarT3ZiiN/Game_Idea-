#pragma once
 
#include "GlobalStates.h"
 
// GlobalStateContext carrega o estado atual, anterior,
// e o estado pré-pause (necessário para restaurar corretamente
// quando o jogador sair do menu de pausa durante uma corrida ou perseguição).
 
struct GlobalStateContext
{
    EGlobalState CurrentState  = EGlobalState::Loading;
    EGlobalState PreviousState = EGlobalState::Invalid;
    EGlobalState PrePauseState = EGlobalState::Invalid; // restaurado ao sair do Paused
};
 