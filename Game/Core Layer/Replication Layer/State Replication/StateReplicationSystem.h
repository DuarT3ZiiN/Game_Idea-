#pragma once

#include <vector>

class StateReplicationSystem
{
public:

    void RegisterEntity(
        const ReplicatedEntity& Entity
    );

    void BuildSnapshot(
        TickID Tick
    );

private:

    std::vector<
        ReplicatedEntity
    > Entities;
};

