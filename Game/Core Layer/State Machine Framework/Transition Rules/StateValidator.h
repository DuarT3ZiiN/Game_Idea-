#pragma once

#include <vector>

#include "StateTransitionRule.h"
#include "GlobalStates.h"

class StateValidator
{
public:

    StateValidator();

    bool IsTransitionValid(
        EGlobalState From,
        EGlobalState To
    ) const;

private:

    std::vector<
        StateTransitionRule<EGlobalState>
    > ValidTransitions;
};

