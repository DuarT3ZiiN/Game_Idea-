#include <cstdlib>

#include "GlobalAllocator.h"

void* GlobalAllocator::Allocate(
    MemorySize Size,
    EMemoryCategory Category,
    const char* File,
    int Line
)
{
    void* Memory =
        malloc(Size);

    AllocationRecord Record;

    Record.Address = Memory;
    Record.Size = Size;
    Record.Category = Category;
    Record.File = File;
    Record.Line = Line;

    LeakTracking.RegisterAllocation(
        Record
    );

    Statistics.TotalAllocated += Size;
    Statistics.CurrentUsage += Size;
    Statistics.AllocationCount++;

    return Memory;
}

void GlobalAllocator::Free(
    void* Address
)
{
    free(Address);

    LeakTracking.RegisterFree(
        Address
    );

    Statistics.FreeCount++;
}
