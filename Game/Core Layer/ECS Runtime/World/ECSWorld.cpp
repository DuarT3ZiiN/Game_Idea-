#include "ECSWorld.h"
 
ECSWorld::ECSWorld()
    : NextIndex(1)
{
}
 
EntityID ECSWorld::CreateEntity()
{
    uint32_t Index;
 
    if (!FreeIndices.empty())
    {
        Index = FreeIndices.front();
        FreeIndices.pop();
    }
    else
    {
        Index = NextIndex++;
    }
 
    if (Index >= static_cast<uint32_t>(EntityRecords.size()))
    {
        EntityRecords.resize(Index + 1);
    }
 
    EntityRecord& Record = EntityRecords[Index];
 
    // Geração já foi incrementada no Destroy; apenas ativa
    Record.ID    = MakeEntityID(Index, Record.Generation);
    Record.Flags = Entity_Active;
 
    return Record.ID;
}
 
void ECSWorld::DestroyEntity(EntityID Entity, ComponentStorage& Components)
{
    if (!IsEntityValid(Entity))
        return;
 
    const uint32_t Index   = GetEntityIndex(Entity);
    EntityRecord&  Record  = EntityRecords[Index];
 
    // Remove todos os componentes dessa entidade
    Components.RemoveAll(Entity);
 
    // Incrementa geração — IDs antigos com a geração anterior ficam inválidos
    Record.Generation = (Record.Generation + 1) & 0xFF;
    Record.Flags      = Entity_PendingKill;
    Record.ID         = INVALID_ENTITY;
 
    FreeIndices.push(Index);
}
 
bool ECSWorld::IsEntityValid(EntityID Entity) const
{
    if (Entity == INVALID_ENTITY)
        return false;
 
    const uint32_t Index = GetEntityIndex(Entity);
 
    if (Index >= static_cast<uint32_t>(EntityRecords.size()))
        return false;
 
    const EntityRecord& Record = EntityRecords[Index];
 
    // Geração deve bater — garante que não é um handle stale
    return (Record.Flags & Entity_Active)
        && GetEntityGeneration(Entity) == Record.Generation;
}
 
EntityRecord* ECSWorld::GetRecord(EntityID Entity)
{
    if (!IsEntityValid(Entity))
        return nullptr;
 
    return &EntityRecords[GetEntityIndex(Entity)];
}
 
const EntityRecord* ECSWorld::GetRecord(EntityID Entity) const
{
    if (!IsEntityValid(Entity))
        return nullptr;
 
    return &EntityRecords[GetEntityIndex(Entity)];
}
 