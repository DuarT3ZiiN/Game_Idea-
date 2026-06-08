
#pragma once

#include <cstdint>

enum class EAsyncJobState : uint8_t
{
    Pending,    // criado, ainda não foi para a fila
    Queued,     // na fila aguardando worker
    Running,    // sendo executado por um worker
    Completed,  // concluído com sucesso
    Failed,     // lançou exceção ou retornou erro
    Retrying,   // falhou e aguarda nova tentativa
    Cancelled   // cancelado antes de executar
};