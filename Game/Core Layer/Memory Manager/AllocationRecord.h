#pragma once

struct AllocationRecord
{
    void* Address = nullptr;

    MemorySize Size = 0;

    EMemoryCategory Category =
        EMemoryCategory::Debug;

    const char* File = nullptr;

    int Line = 0;
};