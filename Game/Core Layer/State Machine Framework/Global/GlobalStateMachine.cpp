#include "GlobalStateMachine.h"
 
GlobalStateMachine::GlobalStateMachine()
{
}
 
EStateTransitionResult GlobalStateMachine::ChangeState(
    EGlobalState NewState
)
{
    if (NewState == EGlobalState::Invalid)
        return EStateTransitionResult::InvalidState;
 
    if (NewState == Context.CurrentState)
        return EStateTransitionResult::Success; // já está no estado, não é erro
 
    if (!Validator.IsTransitionValid(Context.CurrentState, NewState))
        return EStateTransitionResult::IllegalTransition;
 
    ApplyTransition(NewState);
 
    return EStateTransitionResult::Success;
}
 
EStateTransitionResult GlobalStateMachine::Pause()
{
    if (Context.CurrentState == EGlobalState::Paused)
        return EStateTransitionResult::Blocked;
 
    if (!Validator.IsTransitionValid(Context.CurrentState, EGlobalState::Paused))
        return EStateTransitionResult::IllegalTransition;
 
    Context.PrePauseState = Context.CurrentState;
 
    ApplyTransition(EGlobalState::Paused);
 
    return EStateTransitionResult::Success;
}
 
EStateTransitionResult GlobalStateMachine::Unpause()
{
    if (Context.CurrentState != EGlobalState::Paused)
        return EStateTransitionResult::Blocked;
 
    if (Context.PrePauseState == EGlobalState::Invalid)
        return EStateTransitionResult::InvalidState;
 
    const EGlobalState RestoreTarget = Context.PrePauseState;
 
    Context.PrePauseState = EGlobalState::Invalid;
 
    ApplyTransition(RestoreTarget);
 
    return EStateTransitionResult::Success;
}
 
EGlobalState GlobalStateMachine::GetCurrentState() const
{
    return Context.CurrentState;
}
 
EGlobalState GlobalStateMachine::GetPreviousState() const
{
    return Context.PreviousState;
}
 
bool GlobalStateMachine::IsInState(EGlobalState State) const
{
    return Context.CurrentState == State;
}
 
bool GlobalStateMachine::IsPaused() const
{
    return Context.CurrentState == EGlobalState::Paused;
}
 
void GlobalStateMachine::SetOnStateChanged(
    GlobalStateChangedCallback Callback
)
{
    OnStateChanged = std::move(Callback);
}
 
void GlobalStateMachine::ApplyTransition(EGlobalState NewState)
{
    const EGlobalState From = Context.CurrentState;
 
    Context.PreviousState = Context.CurrentState;
    Context.CurrentState  = NewState;
 
    if (OnStateChanged)
        OnStateChanged(From, NewState);
}
 