#pragma once

#include <array>
#include <mutex>
#include <condition_variable>
#include <cstdint>

#include "Job.h"

// JobQueue — ring buffer thread-safe para uma fila de prioridade.
// Capacidade padrão: 512 jobs por nível de prioridade.
//
// Melhoria em relação à versão anterior:
//   - Ring buffer estático em vez de std::queue (sem alocações heap)
//   - WaitAndPop() com condition_variable — workers dormem quando idle
//     em vez de busy-wait (reduz consumo de CPU em frames vazios)
//   - TryPop() não-bloqueante para polling

static constexpr uint32_t JOB_QUEUE_CAPACITY = 512;

class JobQueue
{
public:

    JobQueue() : Head(0), Tail(0), Size(0), bShutdown(false) {}

    bool Push(const Job& InJob);

    // Bloqueia a thread até um job estar disponível ou shutdown
    bool WaitAndPop(Job& OutJob);

    // Retorna false imediatamente se a fila estiver vazia (não bloqueia)
    bool TryPop(Job& OutJob);

    bool     Empty()    const;
    uint32_t GetSize()  const;

    // Acorda todas as threads bloqueadas em WaitAndPop para shutdown
    void SignalShutdown();

private:

    mutable std::mutex              Mutex;
    std::condition_variable         CV;
    std::array<Job, JOB_QUEUE_CAPACITY> Buffer;
    uint32_t                        Head;
    uint32_t                        Tail;
    uint32_t                        Size;
    bool                            bShutdown;
};