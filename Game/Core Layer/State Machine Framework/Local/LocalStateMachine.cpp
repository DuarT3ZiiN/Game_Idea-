#include "LocalStateMachine.h"
 
void LocalStateMachine::ActivateState(ELocalState State)
{
    if (Context.ActiveStates.count(State))
        return; // já ativo, sem-op
 
    Context.ActiveStates.insert(State);
    Context.ActivationTime[State] = CurrentTime;
 
    if (OnActivated)
        OnActivated(State);
}
 
void LocalStateMachine::DeactivateState(ELocalState State)
{
    if (!Context.ActiveStates.count(State))
        return; // já inativo, sem-op
 
    Context.ActiveStates.erase(State);
    Context.ActivationTime.erase(State);
 
    if (OnDeactivated)
        OnDeactivated(State);
}
 
void LocalStateMachine::ActivateExclusive(
    ELocalState FromState,
    ELocalState ToState
)
{
    DeactivateState(FromState);
    ActivateState(ToState);
}
 
bool LocalStateMachine::IsStateActive(ELocalState State) const
{
    return Context.ActiveStates.count(State) > 0;
}
 
double LocalStateMachine::GetActiveDuration(
    ELocalState State,
    double      QueryTime
) const
{
    auto It = Context.ActivationTime.find(State);
 
    if (It == Context.ActivationTime.end())
        return 0.0;
 
    return QueryTime - It->second;
}
 
void LocalStateMachine::Tick(float DeltaTime)
{
    CurrentTime += static_cast<double>(DeltaTime);
 
    // Ponto de extensão: estados com timeout automático podem ser
    // verificados aqui usando GetActiveDuration().
    // Ex: if (GetActiveDuration(ELocalState::DragLaunch, CurrentTime) > 2.0)
    //         DeactivateState(ELocalState::DragLaunch);
}
 
void LocalStateMachine::SetOnActivated(LocalStateCallback Callback)
{
    OnActivated = std::move(Callback);
}
 
void LocalStateMachine::SetOnDeactivated(LocalStateCallback Callback)
{
    OnDeactivated = std::move(Callback);
}
 