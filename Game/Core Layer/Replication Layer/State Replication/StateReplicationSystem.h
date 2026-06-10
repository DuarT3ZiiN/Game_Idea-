#pragma once

#include <vector>

#include "ReplicatedEntity.h"
#include "ReplicationSnapshot.h"
#include "NetworkPriorityRules.h"

class ECSWorld;
class ComponentStorage;
class InterestManager;

// StateReplicationSystem constrói snapshots de replicação a partir do ECS.
//
// Melhorias em relação à versão anterior:
//   - BuildSnapshot recebe ECSWorld e ComponentStorage — a versão anterior
//     tinha apenas um comentário "ECS Query" e não fazia nada
//   - GetLastSnapshots() — expõe o resultado para o ReplicationManager
//     enfileirar nos canais corretos
//   - Usa NetworkPriorityRules para atribuir prioridade por entidade

class StateReplicationSystem
{
public:

    void RegisterEntity(const ReplicatedEntity& Entity);
    void UnregisterEntity(EntityID Entity);

    // Coleta estado atual do ECS e gera snapshots para o tick dado
    void BuildSnapshot(
        TickID            Tick,
        ECSWorld&         World,
        ComponentStorage& Components
    );

    const std::vector<ReplicationSnapshot>& GetLastSnapshots() const;

private:

    std::vector<ReplicatedEntity>       Entities;
    std::vector<ReplicationSnapshot>    LastSnapshots;
};