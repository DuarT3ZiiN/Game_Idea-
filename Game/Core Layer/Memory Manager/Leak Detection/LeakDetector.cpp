#include <iostream>

#include "LeakDetector.h"

void LeakDetector::RegisterAllocation(
    const AllocationRecord&
    Record
)
{
    ActiveAllocations[
        Record.Address
    ] = Record;
}

void LeakDetector::RegisterFree(
    void* Address
)
{
    ActiveAllocations.erase(
        Address
    );
}

void LeakDetector::ReportLeaks()
{
    for (
        const auto& Entry :
        ActiveAllocations
    )
    {
        const AllocationRecord&
        Leak =
            Entry.second;

        std::cout
            << "[LEAK] "
            << Leak.Size
            << " bytes | "
            << Leak.File
            << ":"
            << Leak.Line
            << "\n";
    }
}
