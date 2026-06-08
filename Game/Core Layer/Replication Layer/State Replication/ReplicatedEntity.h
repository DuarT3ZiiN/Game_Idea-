#pragma once

#include "Entity.h"

struct ReplicatedEntity
{
    EntityID Entity;

    NetworkID Owner;

    ENetworkPriority Priority =
        ENetworkPriority::Normal;

    bool bReplicate = true;
};