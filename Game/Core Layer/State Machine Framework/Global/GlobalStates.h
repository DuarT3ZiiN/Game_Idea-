#pragma once
 
#include <cstdint>
 
// Estados globais do jogo — seção 3.3.1 do README
//
// Adicionados em relação à versão anterior:
//   - Loading     : carregamento inicial / troca de distrito
//   - Cutscene    : qualquer sequência cinematográfica (Intro, Rival Introduction, Victory)
//   - Paused      : jogo pausado (menu de pausa, não deve pausar replication)
//
// A máscara de transições válidas fica em StateValidator.
 
enum class EGlobalState : uint8_t
{
    Invalid     = 0,
 
    Loading,        // Carregamento de assets/distrito
    MainMenu,       // Menu principal
    Garage,         // Garagem / tuning
 
    FreeRoam,       // Mundo aberto sem evento ativo
 
    Race,           // Corrida ativa (qualquer modo)
    Pursuit,        // Perseguição policial ativa
    Cutscene,       // Qualquer sequência cinematográfica
 
    Paused,         // Pause (armazena estado anterior)
};
 