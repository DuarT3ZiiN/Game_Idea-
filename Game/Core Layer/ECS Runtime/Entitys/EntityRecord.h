#pragma once
 
#include "Entity.h"
#include "EntityFlags.h"
 
// Registro de uma entidade viva no ECSWorld.
// ArchetypeID identifica qual conjunto de componentes essa entidade possui.
// Generation é incrementada a cada reuso do índice,
// permitindo detectar referências stale (IDs antigos).
 
struct EntityRecord
{
    EntityID   ID           = INVALID_ENTITY;
    uint32_t   ArchetypeID  = 0;
    uint8_t    Generation   = 0;
    uint32_t   Flags        = Entity_Active;
};