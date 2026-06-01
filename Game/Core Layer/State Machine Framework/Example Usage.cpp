
RuntimeStateCoordinator Coordinator;

Coordinator.Initialize();

auto Result =
    Coordinator
    .GetGlobalStateMachine()
    .ChangeState(EGlobalState::FreeRoam);

if (Result ==
    EStateTransitionResult::Success)
{
    printf("Transition Success\n");
}

Coordinator
.GetLocalStateMachine()
.ActivateState(
    ELocalState::Countdown
);
