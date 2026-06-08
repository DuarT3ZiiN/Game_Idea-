#pragma once

class InterestManager
{
public:

    bool ShouldReplicate(
        EntityID Entity,
        NetworkID Client
    );
};