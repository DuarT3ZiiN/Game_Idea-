#pragma once

#include <unordered_map>
#include <memory>

#include "StateReplicationSystem.h"
#include "ClientPrediction.h"
#include "ReconciliationRuntime.h"
#include "NetworkTickManager.h"
#include "ReplicationChannel.h"
#include "InterestManagement.h"

class ECSWorld;
class ComponentStorage;

// ReplicationManager é o ponto de entrada da Replication Layer.
//
// Melhorias em relação à versão anterior:
//   - Tick(DeltaTime, World, Components) — passa ECS para StateReplicationSystem
//     (a versão anterior chamava BuildSnapshot sem argumentos, que era stub)
//   - Gerencia um ReplicationChannel por cliente conectado
//   - Integra InterestManager para filtrar entidades por cliente antes de enfileirar
//   - Initialize conecta ReconciliationRuntime à ClientPrediction

class ReplicationManager
{
public:

    void Initialize();

    void Tick(
        double            DeltaTime,
        ECSWorld&         World,
        ComponentStorage& Components
    );

    // Registra cliente e cria canal para ele
    void RegisterClient(NetworkID ClientID, ENetworkPriority Priority);

    void UnregisterClient(NetworkID ClientID);

    // Registra entidade para replicação
    void RegisterEntity(const ReplicatedEntity& Entity);

    // Recebe estado autoritativo do servidor e dispara reconciliação
    void ReceiveAuthoritativeState(const AuthoritativeState& ServerState);

    InterestManager& GetInterestManager() { return Interest; }

private:

    void DistributeSnapshotsToChannels(
        const std::vector<ReplicationSnapshot>& Snapshots
    );

private:

    StateReplicationSystem StateReplication;
    ClientPrediction       Prediction;
    ReconciliationRuntime  Reconciliation;
    NetworkTickManager     TickManager;
    InterestManager        Interest;

    std::unordered_map<NetworkID, std::unique_ptr<ReplicationChannel>> Channels;
};