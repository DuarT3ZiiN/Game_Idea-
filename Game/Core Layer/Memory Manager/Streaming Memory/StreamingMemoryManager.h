#pragma once

class StreamingMemoryManager
{
public:

    void RegisterTexture(
        MemorySize Size
    );

    void RegisterMesh(
        MemorySize Size
    );

    void RegisterAudio(
        MemorySize Size
    );

    const StreamingMemoryStats&
    GetStats() const;

private:

    StreamingMemoryStats Stats;

    StreamingMemoryBudget Budget;
};
