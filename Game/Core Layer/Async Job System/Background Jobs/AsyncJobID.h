#pragma once

#include <cstdint>
#include <atomic>

using AsyncJobID = uint64_t;

static constexpr AsyncJobID INVALID_ASYNC_JOB = 0;

// Gerador monotônico thread-safe — consistente com GenerateJobID()
// do Task Scheduler para evitar colisões entre os dois sistemas.
// O range do Async Job System começa em 1 << 32 para nunca colidir.
inline AsyncJobID GenerateAsyncJobID()
{
    static std::atomic<AsyncJobID> Counter{ 1ULL << 32 };
    return Counter.fetch_add(1, std::memory_order_relaxed);
}