#pragma once

class NetworkPriorityRules
{
public:

    static ENetworkPriority
    Evaluate(
        float Distance,
        bool Visible,
        bool IsPlayer
    );
};
