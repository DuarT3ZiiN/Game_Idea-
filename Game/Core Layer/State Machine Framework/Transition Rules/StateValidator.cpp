#include "StateValidator.h"

StateValidator::StateValidator()
{
    ValidTransitions.push_back({
        EGlobalState::MainMenu,
        EGlobalState::Garage
    });

    ValidTransitions.push_back({
        EGlobalState::Garage,
        EGlobalState::FreeRoam
    });

    ValidTransitions.push_back({
        EGlobalState::FreeRoam,
        EGlobalState::Race
    });

    ValidTransitions.push_back({
        EGlobalState::Race,
        EGlobalState::Pursuit
    });

    ValidTransitions.push_back({
        EGlobalState::Pursuit,
        EGlobalState::FreeRoam
    });

    ValidTransitions.push_back({
        EGlobalState::Race,
        EGlobalState::FreeRoam
    });
}

bool StateValidator::IsTransitionValid(
    EGlobalState From,
    EGlobalState To
) const
{
    for (const auto& Rule : ValidTransitions)
    {
        if (Rule.From == From
            && Rule.To == To)
        {
            return true;
        }
    }

    return false;
}


