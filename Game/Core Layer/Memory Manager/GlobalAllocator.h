#pragma once

class GlobalAllocator
{
public:

    void* Allocate(
        MemorySize Size,
        EMemoryCategory Category,
        const char* File,
        int Line
    );

    void Free(
        void* Address
    );

private:

    LeakDetector LeakTracking;

    MemoryStatistics Statistics;
};