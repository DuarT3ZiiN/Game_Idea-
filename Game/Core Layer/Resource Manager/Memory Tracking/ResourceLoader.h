#pragma once

#include "AssetReference.h"

enum class ELoadResult : uint8_t
{
    Success,
    FileNotFound,
    UnsupportedFormat,
    OutOfMemory
};

// ResourceLoader carrega e descarrega assets do disco.
//
// Melhorias em relação à versão anterior:
//   - Load retorna ELoadResult + preenche OutData por parâmetro — em vez de
//     retornar void* sem indicação de erro (nullptr era ambíguo: erro ou asset vazio?)
//   - Unload rastreia o ponteiro para liberar a memória corretamente

class ResourceLoader
{
public:

    ELoadResult Load(
        const AssetReference& Reference,
        void*&                OutData
    );

    void Unload(AssetID ID, void* Data);
};