#include "ReplicationManager.h"

void ReplicationManager::Initialize()
{
}

void ReplicationManager::Tick()
{
    TickManager.Tick();

    StateReplication.BuildSnapshot(
        TickManager.GetCurrentTick()
    );
}

