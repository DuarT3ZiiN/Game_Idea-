#include "RuntimeStateCoordinator.h"

void RuntimeStateCoordinator::Initialize()
{
}

void RuntimeStateCoordinator::Update(
    float DeltaTime
)
{
}

GlobalStateMachine&
RuntimeStateCoordinator::GetGlobalStateMachine()
{
    return GlobalMachine;
}

LocalStateMachine&
RuntimeStateCoordinator::GetLocalStateMachine()
{
    return LocalMachine;
}

