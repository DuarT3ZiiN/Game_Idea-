#pragma once

#include "GlobalStates.h"

struct GlobalStateContext
{
    EGlobalState CurrentState =
        EGlobalState::MainMenu;

    EGlobalState PreviousState =
        EGlobalState::MainMenu;
};
