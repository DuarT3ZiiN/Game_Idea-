#pragma once

struct StreamingMemoryBudget
{
    MemorySize TextureBudgetMB = 4096;

    MemorySize MeshBudgetMB = 2048;

    MemorySize AudioBudgetMB = 1024;

    MemorySize DistrictBudgetMB = 4096;
};