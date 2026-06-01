#pragma once
 
#include <cstdint>
 
// EntityID carrega tanto o índice quanto a geração.
// Bits 0-23  → índice (até ~16 milhões de entidades)
// Bits 24-31 → geração (detecta uso de IDs antigos/stale)
 
using EntityID = uint32_t;
 
static constexpr EntityID INVALID_ENTITY   = 0;
static constexpr uint32_t ENTITY_INDEX_BITS = 24;
static constexpr uint32_t ENTITY_GEN_BITS   = 8;
 
static constexpr uint32_t ENTITY_INDEX_MASK = (1u << ENTITY_INDEX_BITS) - 1u;
static constexpr uint32_t ENTITY_GEN_MASK   = (1u << ENTITY_GEN_BITS)  - 1u;
 
inline uint32_t GetEntityIndex(EntityID ID)
{
    return ID & ENTITY_INDEX_MASK;
}
 
inline uint32_t GetEntityGeneration(EntityID ID)
{
    return (ID >> ENTITY_INDEX_BITS) & ENTITY_GEN_MASK;
}
 
inline EntityID MakeEntityID(uint32_t Index, uint32_t Generation)
{
    return (Generation << ENTITY_INDEX_BITS) | (Index & ENTITY_INDEX_MASK);
}
 