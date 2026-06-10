#pragma once

#include "MemoryStatistics.h"

class MemoryTracker
{
public:

    void Allocate(
        uint64_t Bytes
    );

    void Free(
        uint64_t Bytes
    );

    const MemoryStatistics&
    GetStatistics() const;

private:

    MemoryStatistics Stats;
};