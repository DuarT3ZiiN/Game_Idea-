#include "RuntimeStateCoordinator.h"
 
void RuntimeStateCoordinator::Initialize()
{
    // Conecta o callback da GlobalStateMachine
    GlobalMachine.SetOnStateChanged(
        [this](EGlobalState From, EGlobalState To)
        {
            OnGlobalStateChanged(From, To);
        }
    );
 
    // Conecta os callbacks da LocalStateMachine
    LocalMachine.SetOnActivated(
        [this](ELocalState State)
        {
            OnLocalStateActivated(State);
        }
    );
 
    LocalMachine.SetOnDeactivated(
        [this](ELocalState State)
        {
            OnLocalStateDeactivated(State);
        }
    );
 
    // Estado inicial: Loading
    GlobalMachine.ChangeState(EGlobalState::Loading);
}
 
void RuntimeStateCoordinator::Update(float DeltaTime)
{
    // LocalStateMachine precisa de Tick para duração de estados e timeouts
    LocalMachine.Tick(DeltaTime);
}
 
GlobalStateMachine& RuntimeStateCoordinator::GetGlobalMachine()
{
    return GlobalMachine;
}
 
LocalStateMachine& RuntimeStateCoordinator::GetLocalMachine()
{
    return LocalMachine;
}
 
const GlobalStateMachine& RuntimeStateCoordinator::GetGlobalMachine() const
{
    return GlobalMachine;
}
 
const LocalStateMachine& RuntimeStateCoordinator::GetLocalMachine() const
{
    return LocalMachine;
}
 
void RuntimeStateCoordinator::OnGlobalStateChanged(
    EGlobalState From,
    EGlobalState To
)
{
    // Ao sair de uma corrida ou perseguição, limpa os estados locais relacionados.
    // Evita que NitroActive, DriftChain, etc. permaneçam ativos em FreeRoam.
    if (From == EGlobalState::Race || From == EGlobalState::Pursuit)
    {
        LocalMachine.DeactivateState(ELocalState::NitroActive);
        LocalMachine.DeactivateState(ELocalState::DriftChain);
        LocalMachine.DeactivateState(ELocalState::DriftEntry);
        LocalMachine.DeactivateState(ELocalState::DragLaunch);
        LocalMachine.DeactivateState(ELocalState::DragShiftWindow);
        LocalMachine.DeactivateState(ELocalState::FinalLap);
        LocalMachine.DeactivateState(ELocalState::Countdown);
        LocalMachine.DeactivateState(ELocalState::PoliceEscalation);
        LocalMachine.DeactivateState(ELocalState::PursuitSearchMode);
        LocalMachine.DeactivateState(ELocalState::PursuitCooldown);
    }
 
    // TODO: publicar evento no EventBus quando disponível
    // Event E;
    // E.NameID   = EventNames::OnGlobalStateChanged;
    // E.Priority = EEventPriority::High;
    // GlobalBus.PublishImmediate(E);
}
 
void RuntimeStateCoordinator::OnLocalStateActivated(ELocalState State)
{
    // TODO: publicar evento no EventBus quando disponível
    // Permite que HUD, Audio e outros sistemas reajam sem acoplamento direto
    (void)State;
}
 
void RuntimeStateCoordinator::OnLocalStateDeactivated(ELocalState State)
{
    (void)State;
}
 