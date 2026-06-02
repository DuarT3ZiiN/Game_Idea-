
// ── Example Usage — State Machine Framework ──────────────────────────────────
//
// Inicialização
//
 
RuntimeStateCoordinator Coordinator;
Coordinator.Initialize();
 
// Callback de mudança global (ex: conectar ao EventBus)
Coordinator.GetGlobalMachine().SetOnStateChanged(
    [](EGlobalState From, EGlobalState To)
    {
        printf("Global: %d -> %d\n",
            static_cast<int>(From),
            static_cast<int>(To)
        );
    }
);
 
//
// Transição para FreeRoam após loading
//
auto Result = Coordinator.GetGlobalMachine()
    .ChangeState(EGlobalState::FreeRoam);
 
// Result == EStateTransitionResult::Success
 
//
// Iniciar corrida
//
Coordinator.GetGlobalMachine().ChangeState(EGlobalState::Race);
 
// Ativar countdown local
Coordinator.GetLocalMachine().ActivateState(ELocalState::Countdown);
 
//
// Drift chain + nitro simultâneos (estados locais não são exclusivos)
//
Coordinator.GetLocalMachine().ActivateState(ELocalState::DriftChain);
Coordinator.GetLocalMachine().ActivateState(ELocalState::NitroActive);
 
// Verificar duração do drift (para scoring)
double DriftDuration = Coordinator.GetLocalMachine()
    .GetActiveDuration(ELocalState::DriftChain, CurrentGameTime);
 
//
// Drag: transição exclusiva entre janelas
//
Coordinator.GetLocalMachine().ActivateState(ELocalState::DragLaunch);
 
// Quando o launch termina e a janela de shift começa:
Coordinator.GetLocalMachine().ActivateExclusive(
    ELocalState::DragLaunch,
    ELocalState::DragShiftWindow
);
 
//
// Pause durante a corrida
//
Coordinator.GetGlobalMachine().Pause();
// Result == Success, estado salvo como PrePauseState = Race
 
Coordinator.GetGlobalMachine().Unpause();
// Retorna para Race automaticamente
 
//
// Transição ilegal (seria bloqueada)
//
auto BadResult = Coordinator.GetGlobalMachine()
    .ChangeState(EGlobalState::Garage); // Garage a partir de Race é ilegal
 
// BadResult == EStateTransitionResult::IllegalTransition
 
//
// Update — deve ser chamado todo frame
//
Coordinator.Update(DeltaTime);