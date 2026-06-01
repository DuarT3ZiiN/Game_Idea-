#include "GlobalStateMachine.h"

GlobalStateMachine::GlobalStateMachine()
{
}

EStateTransitionResult
GlobalStateMachine::ChangeState(
    EGlobalState NewState
)
{
    if (!Validator.IsTransitionValid(
        Context.CurrentState,
        NewState
    ))
    {
        return
            EStateTransitionResult::
            IllegalTransition;
    }

    Context.PreviousState =
        Context.CurrentState;

    Context.CurrentState =
        NewState;

    return
        EStateTransitionResult::
        Success;
}

EGlobalState
GlobalStateMachine::GetCurrentState() const
{
    return Context.CurrentState;
}

EGlobalState
GlobalStateMachine::GetPreviousState() const
{
    return Context.PreviousState;
}

