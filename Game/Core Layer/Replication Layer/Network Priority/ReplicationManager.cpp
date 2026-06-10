#include "ReplicationManager.h"

void ReplicationManager::Initialize()
{
    Reconciliation.Initialize(&Prediction);
}

void ReplicationManager::Tick(
    double            DeltaTime,
    ECSWorld&         World,
    ComponentStorage& Components
)
{
    const uint32_t TicksFired = TickManager.Tick(DeltaTime);

    // Só replica em ticks de rede — não a cada frame de render
    if (TicksFired == 0)
        return;

    StateReplication.BuildSnapshot(
        TickManager.GetCurrentTick(),
        World,
        Components
    );

    DistributeSnapshotsToChannels(StateReplication.GetLastSnapshots());

    // Flush dos canais — envia dados (stub: callback vazio por ora)
    for (auto& [ClientID, Channel] : Channels)
    {
        Channel->Flush(
            [](NetworkID, const DeltaSnapshot&)
            {
                // TODO: passar para a camada de transporte de rede real
            }
        );
    }
}

void ReplicationManager::RegisterClient(
    NetworkID        ClientID,
    ENetworkPriority Priority
)
{
    auto Channel = std::make_unique<ReplicationChannel>();
    Channel->Initialize(ClientID, Priority);
    Channels[ClientID] = std::move(Channel);
}

void ReplicationManager::UnregisterClient(NetworkID ClientID)
{
    Channels.erase(ClientID);
}

void ReplicationManager::RegisterEntity(const ReplicatedEntity& Entity)
{
    StateReplication.RegisterEntity(Entity);
}

void ReplicationManager::ReceiveAuthoritativeState(
    const AuthoritativeState& ServerState
)
{
    Reconciliation.ReceiveServerState(ServerState);
}

void ReplicationManager::DistributeSnapshotsToChannels(
    const std::vector<ReplicationSnapshot>& Snapshots
)
{
    for (auto& [ClientID, Channel] : Channels)
    {
        for (const ReplicationSnapshot& Snapshot : Snapshots)
        {
            // Filtra por interesse — não envia entidades fora do AOI do cliente
            if (!Interest.ShouldReplicate(Snapshot.Entity, ClientID))
                continue;

            Channel->QueueSnapshot(Snapshot);
        }
    }
}