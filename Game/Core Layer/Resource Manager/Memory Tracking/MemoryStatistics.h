#pragma once

#include <cstdint>

struct MemoryStatistics
{
    uint64_t TotalAllocated = 0;
    uint64_t TotalUsed      = 0;
    uint64_t TotalCached    = 0;
    uint64_t PeakUsage      = 0;

    // Retorna true se TotalUsed excede o budget fornecido
    bool IsOverBudget(uint64_t BudgetBytes) const
    {
        return TotalUsed > BudgetBytes;
    }

    uint64_t RemainingBytes(uint64_t BudgetBytes) const
    {
        return (TotalUsed < BudgetBytes)
            ? BudgetBytes - TotalUsed
            : 0;
    }
};