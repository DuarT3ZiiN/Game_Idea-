#pragma once

#include <cstdint>

enum EntityFlags : uint32_t
{
    Entity_Active      = 1 << 0,
    Entity_Replicated  = 1 << 1,
    Entity_Persistent  = 1 << 2,
    Entity_PendingKill = 1 << 3
};