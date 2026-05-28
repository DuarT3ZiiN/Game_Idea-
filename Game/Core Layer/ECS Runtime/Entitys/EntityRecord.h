#pragma once

#include "Entity.h"
#include "EntityFlags.h"

struct EntityRecord
{
    EntityID ID = INVALID_ENTITY;

    uint32_t ArchetypeIndex = 0;
    uint32_t ChunkIndex = 0;
    uint32_t ComponentIndex = 0;

    uint32_t Flags = Entity_Active;
};
