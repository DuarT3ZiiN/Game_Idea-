#include "ReplicationChannel.h"

void ReplicationChannel::
QueueSnapshot(
    const ReplicationSnapshot&
    Snapshot
)
{
    PendingSnapshots.push_back(
        Snapshot
    );
}