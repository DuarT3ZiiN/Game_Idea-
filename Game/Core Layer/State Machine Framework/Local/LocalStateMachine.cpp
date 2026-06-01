#include "LocalStateMachine.h"

void LocalStateMachine::ActivateState(
    ELocalState State
)
{
    Context.ActiveStates.insert(State);
}

void LocalStateMachine::DeactivateState(
    ELocalState State
)
{
    Context.ActiveStates.erase(State);
}

bool LocalStateMachine::IsStateActive(
    ELocalState State
) const
{
    return
        Context.ActiveStates.find(State)
        != Context.ActiveStates.end();
}

