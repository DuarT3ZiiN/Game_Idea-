#include "StreamingMemoryManager.h"

void StreamingMemoryManager::
RegisterTexture(
    MemorySize Size
)
{
    Stats.TextureUsage += Size;
}

void StreamingMemoryManager::
RegisterMesh(
    MemorySize Size
)
{
    Stats.MeshUsage += Size;
}

void StreamingMemoryManager::
RegisterAudio(
    MemorySize Size
)
{
    Stats.AudioUsage += Size;
}

const StreamingMemoryStats&
StreamingMemoryManager::
GetStats() const
{
    return Stats;
}