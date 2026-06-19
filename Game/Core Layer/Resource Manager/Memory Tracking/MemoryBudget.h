#pragma once

#include <cstdint>

// MemoryBudget define os limites de memória por categoria de asset.
//
// Melhorias em relação à versão anterior:
//   - IsOverBudget() por categoria — ResourceManager verifica antes de carregar
//   - TotalBudgetMB() calculado — para o MemoryTracker comparar com TotalAllocated

struct MemoryBudget
{
    uint64_t TextureBudgetMB   = 2048;
    uint64_t MeshBudgetMB      = 2048;
    uint64_t AudioBudgetMB     = 1024;
    uint64_t StreamingBudgetMB = 4096;

    uint64_t TotalBudgetMB() const
    {
        return TextureBudgetMB
             + MeshBudgetMB
             + AudioBudgetMB
             + StreamingBudgetMB;
    }

    uint64_t TotalBudgetBytes() const
    {
        return TotalBudgetMB() * 1024ULL * 1024ULL;
    }
};