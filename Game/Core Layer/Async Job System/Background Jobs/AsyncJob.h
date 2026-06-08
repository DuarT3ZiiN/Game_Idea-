#pragma once

#include <functional>
#include <atomic>
#include <memory>

#include "AsyncJobID.h"
#include "AsyncJobTypes.h"
#include "AsyncJobState.h"

// AsyncJob representa uma unidade de trabalho assíncrona de background.
//
// Melhorias em relação à versão anterior:
//   - ID gerado automaticamente via GenerateAsyncJobID()
//   - OnComplete / OnFailed callbacks — chamados pelo AsyncWorker
//     após a execução, sem polling no main thread
//   - MaxRetries — se > 0, o worker recoloca o job na fila em caso de falha
//   - bCompleted atômico — polling opcional sem bloquear
//   - State é shared_ptr para permitir tracking externo (ex: AsyncJobManager)

struct AsyncJob
{
    AsyncJobID     ID        = GenerateAsyncJobID();
    EAsyncJobType  Type      = EAsyncJobType::Background;
    const char*    DebugName = "";

    // Estado compartilhado — permite consulta externa thread-safe
    std::shared_ptr<std::atomic<EAsyncJobState>> State =
        std::make_shared<std::atomic<EAsyncJobState>>(
            EAsyncJobState::Pending
        );

    // Trabalho principal
    std::function<void()> Execute;

    // Chamado pelo worker ao concluir com sucesso
    std::function<void(AsyncJobID)> OnComplete;

    // Chamado pelo worker ao falhar (após esgotar retries)
    std::function<void(AsyncJobID)> OnFailed;

    // Quantas vezes o job pode ser reexecutado após falha
    uint8_t MaxRetries     = 0;
    uint8_t RetryCount     = 0;
};