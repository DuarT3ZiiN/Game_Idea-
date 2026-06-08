#pragma once

#include <thread>
#include <atomic>

class AsyncJobQueue;

// AsyncWorker consome jobs de uma AsyncJobQueue.
//
// Melhorias em relação à versão anterior:
//   - WaitAndPop em vez de Pop + busy-wait (workers dormem quando ociosos)
//   - Chama OnComplete / OnFailed após execução
//   - Suporte a retry: recoloca o job na fila se RetryCount < MaxRetries
//   - Atualiza State atômico do job (Queued → Running → Completed/Failed)
//   - Stop() usa SignalShutdown para acordar workers bloqueados

class AsyncWorker
{
public:

    // RetryQueue pode ser a mesma Queue ou uma fila separada de baixa prioridade
    explicit AsyncWorker(
        AsyncJobQueue* InQueue,
        AsyncJobQueue* InRetryQueue = nullptr
    );

    ~AsyncWorker();

    void Start();
    void Stop();

private:

    void Run();

private:

    std::thread       WorkerThread;
    std::atomic<bool> Running;

    AsyncJobQueue* Queue;
    AsyncJobQueue* RetryQueue;
};