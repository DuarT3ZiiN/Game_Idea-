#pragma once

#include <unordered_map>

class LeakDetector
{
public:

    void RegisterAllocation(
        const AllocationRecord&
        Record
    );

    void RegisterFree(
        void* Address
    );

    void ReportLeaks();

private:

    std::unordered_map
    <
        void*,
        AllocationRecord
    > ActiveAllocations;
};