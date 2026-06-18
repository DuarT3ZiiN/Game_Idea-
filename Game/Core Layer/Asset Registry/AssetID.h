#pragma once

#include <cstdint>
#include <atomic>

using AssetID = uint64_t;

static constexpr AssetID INVALID_ASSET_ID = 0;

// Gerador monotônico thread-safe — range 1<<48 para não colidir
// com JobID (1<<32) nem AsyncJobID (1<<32).
inline AssetID GenerateAssetID()
{
    static std::atomic<AssetID> Counter{ 1ULL << 48 };
    return Counter.fetch_add(1, std::memory_order_relaxed);
}