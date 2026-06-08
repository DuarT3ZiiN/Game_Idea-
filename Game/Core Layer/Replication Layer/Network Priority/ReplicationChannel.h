#pragma once

#include <vector>

class ReplicationChannel
{
public:

    void QueueSnapshot(
        const ReplicationSnapshot&
        Snapshot
    );

private:

    std::vector<
        ReplicationSnapshot
    > PendingSnapshots;
};
