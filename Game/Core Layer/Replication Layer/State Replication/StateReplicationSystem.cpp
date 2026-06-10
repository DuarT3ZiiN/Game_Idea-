#include "StateReplicationSystem.h"

#include "ECSWorld.h"
#include "ComponentStorage.h"

#include <algorithm>
#include <cmath>

void StateReplicationSystem::RegisterEntity(
    const ReplicatedEntity& Entity
)
{
    // Evita duplicatas
    for (const auto& E : Entities)
    {
        if (E.Entity == Entity.Entity)
            return;
    }

    Entities.push_back(Entity);
}

void StateReplicationSystem::UnregisterEntity(EntityID Entity)
{
    Entities.erase(
        std::remove_if(
            Entities.begin(),
            Entities.end(),
            [Entity](const ReplicatedEntity& E) { return E.Entity == Entity; }
        ),
        Entities.end()
    );
}

void StateReplicationSystem::BuildSnapshot(
    TickID            Tick,
    ECSWorld&         World,
    ComponentStorage& Components
)
{
    LastSnapshots.clear();
    LastSnapshots.reserve(Entities.size());

    auto& TransformSet = Components.TransformComponents;
    auto& VelocitySet  = Components.VelocityComponents;

    for (const ReplicatedEntity& RE : Entities)
    {
        if (!RE.bReplicate)
            continue;

        if (!World.IsEntityValid(RE.Entity))
            continue;

        const TransformComponent* T = TransformSet.Get(RE.Entity);

        if (!T)
            continue;

        ReplicationSnapshot Snapshot;
        Snapshot.Tick   = Tick;
        Snapshot.Entity = RE.Entity;

        Snapshot.Transform.PositionX = T->Position.X;
        Snapshot.Transform.PositionY = T->Position.Y;
        Snapshot.Transform.PositionZ = T->Position.Z;

        const VelocityComponent* Vel = VelocitySet.Get(RE.Entity);

        if (Vel)
        {
            const float VX = Vel->LinearVelocity.X;
            const float VY = Vel->LinearVelocity.Y;
            const float VZ = Vel->LinearVelocity.Z;

            Snapshot.Speed    = sqrtf(VX * VX + VY * VY + VZ * VZ);
            Snapshot.Velocity = Snapshot.Speed;
        }

        LastSnapshots.push_back(Snapshot);
    }
}

const std::vector<ReplicationSnapshot>&
StateReplicationSystem::GetLastSnapshots() const
{
    return LastSnapshots;
}