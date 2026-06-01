#pragma once

#include "LocalStateContext.h"

class LocalStateMachine
{
public:

    void ActivateState(
        ELocalState State
    );

    void DeactivateState(
        ELocalState State
    );

    bool IsStateActive(
        ELocalState State
    ) const;

private:

    LocalStateContext Context;
};
