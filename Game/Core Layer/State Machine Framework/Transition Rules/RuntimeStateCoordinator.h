#pragma once
 
#include "GlobalStateMachine.h"
#include "LocalStateMachine.h"
 
// RuntimeStateCoordinator é o ponto central de acesso ao State Machine Framework.
//
// Responsabilidades (seção 3.3 do README):
//   - Inicializar Global e Local machines
//   - Fazer Tick das duas máquinas a cada frame
//   - Expor acesso controlado (ref, não ponteiro nulo)
//   - Conectar callbacks para integração com EventBus e GlobalDirector
//
// Uso correto:
//   Coordinator.Initialize();
//   Coordinator.GetGlobalMachine().ChangeState(EGlobalState::FreeRoam);
//   Coordinator.Update(DeltaTime);  // deve ser chamado 1x por frame
 
class RuntimeStateCoordinator
{
public:
 
    // Inicializa as máquinas e registra callbacks padrão
    void Initialize();
 
    // Deve ser chamado 1x por frame pelo game loop principal
    void Update(float DeltaTime);
 
    // Getters — retornam referência para evitar cópias acidentais
    GlobalStateMachine& GetGlobalMachine();
    LocalStateMachine&  GetLocalMachine();
 
    const GlobalStateMachine& GetGlobalMachine() const;
    const LocalStateMachine&  GetLocalMachine()  const;
 
private:
 
    // Chamado quando GlobalStateMachine muda de estado
    void OnGlobalStateChanged(EGlobalState From, EGlobalState To);
 
    // Chamado quando LocalStateMachine ativa um estado
    void OnLocalStateActivated(ELocalState State);
 
    // Chamado quando LocalStateMachine desativa um estado
    void OnLocalStateDeactivated(ELocalState State);
 
private:
 
    GlobalStateMachine GlobalMachine;
    LocalStateMachine  LocalMachine;
};