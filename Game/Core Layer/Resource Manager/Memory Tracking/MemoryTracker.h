#pragma once

#include <unordered_map>

#include "MemoryStatistics.h"
#include "MemoryBudget.h"
#include "AssetID.h"

// MemoryTracker rastreia uso de memória por asset e por total.
//
// Melhorias em relação à versão anterior:
//   - TrackAsset(ID, Bytes) / UntrackAsset(ID) — rastreamento granular
//     por asset para o ResourceManager saber o custo individual
//   - IsOverBudget() — compara TotalUsed com o budget configurado
//   - GetAssetMemory(ID) — consulta o custo de um asset específico

class MemoryTracker
{
public:

    void Initialize(const MemoryBudget& InBudget);

    void Allocate(uint64_t Bytes);
    void Free(uint64_t Bytes);

    // Rastreamento por asset — chamado pelo ResourceManager ao carregar/descarregar
    void TrackAsset  (AssetID ID, uint64_t Bytes);
    void UntrackAsset(AssetID ID);

    uint64_t GetAssetMemory(AssetID ID) const;

    bool IsOverBudget() const;

    const MemoryStatistics& GetStatistics() const;

private:

    MemoryStatistics                          Stats;
    MemoryBudget                              Budget;
    std::unordered_map<AssetID, uint64_t>     AssetMemory;
};