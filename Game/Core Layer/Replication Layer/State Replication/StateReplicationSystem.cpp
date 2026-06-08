#include "StateReplicationSystem.h"

void StateReplicationSystem::RegisterEntity(
    const ReplicatedEntity& Entity
)
{
    Entities.push_back(Entity);
}

void StateReplicationSystem::BuildSnapshot(
    TickID Tick
)
{
    // ECS Query

    // coletar componentes
    // gerar snapshot
}

