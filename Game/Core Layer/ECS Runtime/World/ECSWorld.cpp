#include "ECSWorld.h"

ECSWorld::ECSWorld()
{
    NextEntityID = 1;
}

EntityID ECSWorld::CreateEntity()
{
    EntityID NewEntity;

    if (!FreeEntities.empty())
    {
        NewEntity = FreeEntities.front();
        FreeEntities.pop();
    }
    else
    {
        NewEntity = NextEntityID++;
    }

    if (NewEntity >= EntityRecords.size())
    {
        EntityRecords.resize(NewEntity + 1);
    }

    EntityRecord& Record = EntityRecords[NewEntity];

    Record.ID = NewEntity;
    Record.Flags = Entity_Active;

    return NewEntity;
}

void ECSWorld::DestroyEntity(EntityID Entity)
{
    if (!IsEntityValid(Entity))
        return;

    EntityRecord& Record = EntityRecords[Entity];

    Record.Flags = Entity_PendingKill;

    FreeEntities.push(Entity);
}

bool ECSWorld::IsEntityValid(EntityID Entity) const
{
    return Entity != INVALID_ENTITY
        && Entity < EntityRecords.size()
        && EntityRecords[Entity].Flags & Entity_Active;
}

EntityRecord* ECSWorld::GetRecord(EntityID Entity)
{
    if (!IsEntityValid(Entity))
        return nullptr;

    return &EntityRecords[Entity];
}

