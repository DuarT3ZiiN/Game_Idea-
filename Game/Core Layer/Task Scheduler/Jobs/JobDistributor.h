#pragma once

#include <vector>
#include <utility>
#include <cstdint>

// JobDistributor divide trabalho entre workers.
//
// SplitWork — divide N itens em K chunks para paralelismo de dados
// (ex: 1000 entidades entre 6 workers = 6 chunks de ~166)

class JobDistributor
{
public:

    // Retorna pares (Start, End) para cada worker.
    // O último chunk absorve o restante da divisão inteira.
    static std::vector<std::pair<uint32_t, uint32_t>> SplitWork(
        uint32_t TotalItems,
        uint32_t WorkerCount
    );

    // Retorna o tamanho ótimo de chunk dado o total e o count de workers
    static uint32_t OptimalChunkSize(
        uint32_t TotalItems,
        uint32_t WorkerCount
    );
};