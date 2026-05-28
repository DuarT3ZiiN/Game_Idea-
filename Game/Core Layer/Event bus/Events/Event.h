#pragma once

#include <string>
#include <chrono>

#include "EventTypes.h"
#include "Entity.h"

struct Event
{
    EventID ID = 0;

    std::string Name;

    EEventType Type =
        EEventType::Global;

    EEventPriority Priority =
        EEventPriority::Normal;

    EntityID SourceEntity =
        INVALID_ENTITY;

    double Timestamp = 0.0;

    bool bReplicated = false;

    bool bReplayable = true;
};
