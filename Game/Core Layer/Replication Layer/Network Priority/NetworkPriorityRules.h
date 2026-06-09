#pragma once

#include "ReplicationPriority.h"
#include "ReplicatedEntity.h"

class NetworkPriorityRules
{
public:

    // Avalia por parâmetros individuais (para chamadas manuais)
    static ENetworkPriority Evaluate(
        float Distance,
        bool  bVisible,
        bool  bIsPlayer
    );

    // Avalia diretamente a partir de uma ReplicatedEntity
    static ENetworkPriority EvaluateEntity(
        const ReplicatedEntity& Entity,
        float                   DistanceToLocalPlayer
    );
};