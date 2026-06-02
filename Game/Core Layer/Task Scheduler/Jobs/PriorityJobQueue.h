#pragma once

#include "JobQueue.h"

// PriorityJobQueue mantém 4 filas por nível de prioridade.
// Pop drena Critical → High → Normal → Low em ordem.
//
// WaitAndPop usa poll entre filas pois condition_variable
// não pode aguardar múltiplas fontes nativamente em C++.
// Para um jogo de corrida com taxa de jobs alta, isso é aceitável.

class PriorityJobQueue
{
public:

    bool Push(const Job& InJob);

    // Tenta popular da fila de maior prioridade disponível (não bloqueia)
    bool TryPop(Job& OutJob);

    // Bloqueia esperando por qualquer job — usa polling com sleep curto
    bool WaitAndPop(Job& OutJob);

    bool IsEmpty() const;

    // Propaga shutdown para todas as filas internas
    void SignalShutdown();

private:

    JobQueue CriticalQueue;
    JobQueue HighQueue;
    JobQueue NormalQueue;
    JobQueue LowQueue;
};