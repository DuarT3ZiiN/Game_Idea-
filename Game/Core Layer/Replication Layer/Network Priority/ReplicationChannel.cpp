#include "ReplicationChannel.h"

void ReplicationChannel::Initialize(
    NetworkID        InClientID,
    ENetworkPriority InPriority
)
{
    ClientID = InClientID;
    Priority = InPriority;
}

void ReplicationChannel::QueueSnapshot(
    const ReplicationSnapshot& Snapshot
)
{
    PendingSnapshots.push_back(Snapshot);
}

uint32_t ReplicationChannel::Flush(
    const SnapshotSendCallback& SendCallback
)
{
    if (!SendCallback || PendingSnapshots.empty())
        return 0;

    uint32_t Sent = 0;

    for (const ReplicationSnapshot& Snapshot : PendingSnapshots)
    {
        auto It = LastSentSnapshots.find(Snapshot.Entity);

        if (It != LastSentSnapshots.end())
        {
            // Delta compression: só envia o que mudou
            DeltaSnapshot Delta = SnapshotCompressor::Compress(
                It->second,
                Snapshot
            );

            // Se nenhum campo mudou além do threshold, pula o envio
            if (!Delta.bHasPosition && !Delta.bHasRotation && !Delta.bHasVelocity)
                continue;

            SendCallback(ClientID, Delta);
            It->second = Snapshot;
        }
        else
        {
            // Primeiro envio desta entidade — snapshot completo como baseline
            DeltaSnapshot FullDelta;
            FullDelta.Tick        = Snapshot.Tick;
            FullDelta.Entity      = Snapshot.Entity;
            FullDelta.bHasPosition = true;
            FullDelta.bHasRotation = true;
            FullDelta.bHasVelocity = true;
            FullDelta.PositionX   = Snapshot.Transform.PositionX;
            FullDelta.PositionY   = Snapshot.Transform.PositionY;
            FullDelta.PositionZ   = Snapshot.Transform.PositionZ;
            FullDelta.RotationX   = Snapshot.Transform.RotationX;
            FullDelta.RotationY   = Snapshot.Transform.RotationY;
            FullDelta.RotationZ   = Snapshot.Transform.RotationZ;
            FullDelta.RotationW   = Snapshot.Transform.RotationW;
            FullDelta.Speed       = Snapshot.Speed;
            FullDelta.Throttle    = Snapshot.Throttle;
            FullDelta.Steering    = Snapshot.Steering;

            SendCallback(ClientID, FullDelta);
            LastSentSnapshots[Snapshot.Entity] = Snapshot;
        }

        ++Sent;
    }

    PendingSnapshots.clear();

    return Sent;
}

uint32_t ReplicationChannel::PendingCount() const
{
    return static_cast<uint32_t>(PendingSnapshots.size());
}