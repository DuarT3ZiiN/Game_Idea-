#pragma once

#include <vector>
#include <queue>

#include "EntityRecord.h"

class ECSWorld
{
public:

    ECSWorld();

    EntityID CreateEntity();

    void DestroyEntity(EntityID Entity);

    bool IsEntityValid(EntityID Entity) const;

    EntityRecord* GetRecord(EntityID Entity);

private:

    EntityID NextEntityID;

    std::vector<EntityRecord> EntityRecords;

    std::queue<EntityID> FreeEntities;
};

