#include "NetworkPriorityRules.h"

ENetworkPriority
NetworkPriorityRules::Evaluate(
    float Distance,
    bool Visible,
    bool IsPlayer
)
{
    if (IsPlayer)
    {
        return
            ENetworkPriority::
            Critical;
    }

    if (
        Visible &&
        Distance < 150.0f
    )
    {
        return
            ENetworkPriority::
            High;
    }

    if (
        Distance < 400.0f
    )
    {
        return
            ENetworkPriority::
            Normal;
    }

    return
        ENetworkPriority::
        Low;
}

