#pragma once

#include <vector>

#include "StreamingResourceRequest.h"

// FutureStreamingManager (stub) gerencia o carregamento assíncrono de assets.
// Será conectado ao AsyncJobManager quando implementado completamente.
//
// Melhorias em relação à versão anterior:
//   - Includes presentes (versão anterior usava StreamingRequest sem include)
//   - CancelByDistrict(DistrictID) — cancela todos os requests de uma região
//     ao fazer unload de distrito (integração com LocalEventBus OnDistrictUnloaded)
//   - Update(DeltaTime) — assinatura correta para o game loop

class FutureStreamingManager
{
public:

    void RequestAsset(const StreamingRequest& Request);

    // Cancela todos os requests pendentes de um distrito
    void CancelByDistrict(uint32_t DistrictID);

    // Processa requests pendentes — deve ser chamado uma vez por frame
    void Update(float DeltaTime);

    uint32_t GetPendingCount() const;

private:

    std::vector<StreamingRequest> PendingRequests;
};