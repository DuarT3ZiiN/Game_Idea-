#pragma once

#include "EventNameID.h"

struct EventListener
{
    uint64_t ListenerID = 0;

    EventCallback Callback;
};