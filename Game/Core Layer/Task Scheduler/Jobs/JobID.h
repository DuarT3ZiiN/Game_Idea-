#pragma once
 
#include <cstdint>
#include <atomic>
 
using JobID = uint64_t;
 
static constexpr JobID INVALID_JOB = 0;
 
// Gerador de IDs únicos e monotônicos para jobs.
// Thread-safe via atomic.
inline JobID GenerateJobID()
{
    static std::atomic<JobID> Counter{ 1 };
    return Counter.fetch_add(1, std::memory_order_relaxed);
}
 