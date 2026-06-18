#pragma once

#include <string>

struct AIDebugInfo
{
    uint64_t EntityID = 0;

    std::string CurrentState;

    std::string CurrentDecision;

    float Aggression = 0.0f;

    float Confidence = 0.0f;
};