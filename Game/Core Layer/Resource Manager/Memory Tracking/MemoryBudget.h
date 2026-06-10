#pragma once

struct MemoryBudget
{
    uint64_t TextureBudgetMB = 2048;

    uint64_t MeshBudgetMB = 2048;

    uint64_t AudioBudgetMB = 1024;

    uint64_t StreamingBudgetMB = 4096;
};