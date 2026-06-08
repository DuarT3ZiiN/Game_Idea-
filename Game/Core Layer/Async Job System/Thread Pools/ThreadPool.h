#pragma once

#include <vector>
#include <memory>

#include "AsyncWorker.h"
#include "AsyncJobQueue.h"
#include "ThreadPoolConfig.h"

// ThreadPool gerencia um conjunto de AsyncWorkers e uma fila compartilhada.
//
// Melhorias em relação à versão anterior:
//   - Shutdown() propaga SignalShutdown para acordar workers bloqueados
//     (versão anterior ficava deadlock se workers estivessem em busy-wait)
//   - GetQueueSize() para monitoramento externo
//   - IsIdle() — retorna true quando a fila está vazia (útil para testes)
//   - WorkerCount resolvido via ThreadPoolConfig::ResolvedWorkerCount()

class ThreadPool
{
public:

    void Initialize(const ThreadPoolConfig& Config);

    void Shutdown();

    bool Submit(const AsyncJob& Job);

    uint32_t GetWorkerCount() const;
    uint32_t GetQueueSize()   const;
    bool     IsIdle()         const;

private:

    ThreadPoolConfig Settings;
    AsyncJobQueue    Queue;

    std::vector<std::unique_ptr<AsyncWorker>> Workers;
};