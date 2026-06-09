#include "NetworkPriorityRules.h"

ENetworkPriority NetworkPriorityRules::Evaluate(
    float Distance,
    bool  bVisible,
    bool  bIsPlayer
)
{
    if (bIsPlayer)
        return ENetworkPriority::Critical;

    if (bVisible && Distance < 150.f)
        return ENetworkPriority::High;

    if (Distance < 400.f)
        return ENetworkPriority::Normal;

    return ENetworkPriority::Low;
}

ENetworkPriority NetworkPriorityRules::EvaluateEntity(
    const ReplicatedEntity& Entity,
    float                   DistanceToLocalPlayer
)
{
    // Entidade marcada como player → sempre Critical
    if (Entity.bIsPlayer)
        return ENetworkPriority::Critical;

    // Respeita prioridade manual se foi configurada explicitamente
    if (Entity.Priority == ENetworkPriority::Critical)
        return ENetworkPriority::Critical;

    return Evaluate(DistanceToLocalPlayer, true, false);
}