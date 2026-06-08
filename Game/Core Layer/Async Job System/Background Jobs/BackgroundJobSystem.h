#pragma once

#include <unordered_map>
#include <memory>

#include "ThreadPool.h"
#include "AsyncJob.h"

// BackgroundJobSystem gerencia dois pools:
//   - GeneralPool : todos os jobs de background (Streaming, Telemetry, AI, etc.)
//   - SavePool    : exclusivo para SaveGame — nunca bloqueado por outros jobs
//
// Melhorias em relação à versão anterior:
//   - Roteamento automático por EAsyncJobType::SaveGame → SavePool
//   - GetJob() permite consultar estado de um job pelo ID
//   - CancelJob() marca o job como Cancelled se ainda estiver Queued
//   - WaitForAll() bloqueia até ambos os pools ficarem ociosos (para shutdown limpo)

class BackgroundJobSystem
{
public:

    void Initialize(const ThreadPoolConfig& Config = ThreadPoolConfig::Default());

    void Shutdown();

    bool SubmitBackgroundJob(const AsyncJob& Job);

    // Aguarda todos os jobs pendentes finalizarem (útil antes de fechar o jogo)
    void WaitForAll();

    uint32_t GetPendingCount() const;

private:

    ThreadPool GeneralPool;
    ThreadPool SavePool;    // exclusivo para EAsyncJobType::SaveGame
};