#pragma once

#include <unordered_map>
#include <memory>
#include <mutex>

#include "BackgroundJobSystem.h"

// AsyncJobManager é o ponto de entrada público do Async Job System.
//
// Melhorias em relação à versão anterior:
//   - Rastreia todos os jobs submetidos por ID → State compartilhado
//   - IsJobComplete() / GetJobState() sem precisar guardar referência externa
//   - WaitForAll() delega para BackgroundJobSystem
//   - GetPendingCount() para monitoramento (integração com Debug Tools 3.13)

class AsyncJobManager
{
public:

    void Initialize(
        const ThreadPoolConfig& Config = ThreadPoolConfig::Default()
    );

    void Shutdown();

    // Submete e registra o job — retorna INVALID_ASYNC_JOB se a fila estiver cheia
    AsyncJobID Submit(const AsyncJob& Job);

    // Consulta estado de um job pelo ID
    EAsyncJobState GetJobState(AsyncJobID ID) const;

    bool IsJobComplete(AsyncJobID ID) const;

    // Aguarda todos os jobs finalizarem
    void WaitForAll();

    uint32_t GetPendingCount() const;

private:

    BackgroundJobSystem BackgroundSystem;

    // Tracking de estado por ID — removidos automaticamente após conclusão
    mutable std::mutex                                               TrackingMutex;
    std::unordered_map<
        AsyncJobID,
        std::shared_ptr<std::atomic<EAsyncJobState>>
    > TrackedJobs;
};