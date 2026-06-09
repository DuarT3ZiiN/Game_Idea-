#pragma once

#include "Entity.h"
#include "NetworkTypes.h"
#include "ReplicationPriority.h"

struct ReplicatedEntity
{
    EntityID         Entity   = INVALID_ENTITY;
    NetworkID        Owner    = INVALID_NETWORK_ID;

    ENetworkPriority Priority = ENetworkPriority::Normal;

    bool bReplicate  = true;
    bool bIsPlayer   = false; // players sempre Critical
};