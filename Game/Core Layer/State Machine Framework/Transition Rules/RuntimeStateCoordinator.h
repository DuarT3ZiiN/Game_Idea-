#pragma once

#include "GlobalStateMachine.h"
#include "LocalStateMachine.h"

class RuntimeStateCoordinator
{
public:

    void Initialize();

    void Update(float DeltaTime);

    GlobalStateMachine& GetGlobalStateMachine();

    LocalStateMachine& GetLocalStateMachine();

private:

    GlobalStateMachine GlobalMachine;

    LocalStateMachine LocalMachine;
};

