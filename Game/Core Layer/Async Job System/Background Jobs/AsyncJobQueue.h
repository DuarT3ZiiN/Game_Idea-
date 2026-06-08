#pragma once

#include <array>
#include <mutex>
#include <condition_variable>
#include <cstdint>

#include "AsyncJob.h"

// AsyncJobQueue — ring buffer thread-safe com WaitAndPop.
//
// Melhorias em relação à versão anterior:
//   - Ring buffer estático (sem alocações heap por push/pop)
//   - WaitAndPop com condition_variable — workers dormem quando idle
//   - TryPop não-bloqueante para shutdown gracioso
//   - SignalShutdown acorda todos os workers bloqueados
//   - GetSize() para monitoramento externo

static constexpr uint32_t ASYNC_QUEUE_CAPACITY = 1024;

class AsyncJobQueue
{
public:

    AsyncJobQueue();

    bool Push(const AsyncJob& Job);

    // Bloqueia até job disponível ou shutdown
    bool WaitAndPop(AsyncJob& OutJob);

    // Retorna false imediatamente se vazia
    bool TryPop(AsyncJob& OutJob);

    bool     Empty()   const;
    uint32_t GetSize() const;

    void SignalShutdown();

private:

    mutable std::mutex              Mutex;
    std::condition_variable         CV;
    std::array<AsyncJob, ASYNC_QUEUE_CAPACITY> Buffer;
    uint32_t                        Head;
    uint32_t                        Tail;
    uint32_t                        Size;
    bool                            bShutdown;
};