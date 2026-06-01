#pragma once

#include "GlobalStateContext.h"
#include "StateTransitionResult.h"
#include "StateValidator.h"

class GlobalStateMachine
{
public:

    GlobalStateMachine();

    EStateTransitionResult ChangeState(
        EGlobalState NewState
    );

    EGlobalState GetCurrentState() const;

    EGlobalState GetPreviousState() const;

private:

    GlobalStateContext Context;

    StateValidator Validator;
};

