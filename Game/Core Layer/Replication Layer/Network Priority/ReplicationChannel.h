#pragma once

#include <vector>
#include <functional>

#include "ReplicationSnapshot.h"
#include "SnapshotCompression.h"
#include "ReplicationPriority.h"
#include "NetworkTypes.h"

// ReplicationChannel gerencia os snapshots pendentes de envio para um cliente.
//
// Melhorias em relação à versão anterior:
//   - A versão anterior só tinha QueueSnapshot sem nenhuma forma de consumir
//     ou enviar os dados — canal inútil sem Flush
//   - Flush() entrega os snapshots via callback (simulação de envio de rede)
//   - Delta compression via SnapshotCompressor — só envia o que mudou
//   - Priority — canais Critical têm Flush forçado a cada tick
//   - ClientID — identifica para qual cliente este canal pertence

using SnapshotSendCallback = std::function<void(NetworkID, const DeltaSnapshot&)>;

class ReplicationChannel
{
public:

    void Initialize(NetworkID InClientID, ENetworkPriority InPriority);

    void QueueSnapshot(const ReplicationSnapshot& Snapshot);

    // Envia todos os snapshots pendentes via callback
    // Retorna quantos snapshots foram enviados
    uint32_t Flush(const SnapshotSendCallback& SendCallback);

    NetworkID        GetClientID() const { return ClientID; }
    ENetworkPriority GetPriority() const { return Priority; }
    uint32_t         PendingCount() const;

private:

    NetworkID                       ClientID  = INVALID_NETWORK_ID;
    ENetworkPriority                Priority  = ENetworkPriority::Normal;

    std::vector<ReplicationSnapshot> PendingSnapshots;

    // Último snapshot enviado por entidade — baseline para delta compression
    std::unordered_map<EntityID, ReplicationSnapshot> LastSentSnapshots;
};