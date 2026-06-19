#pragma once

#include "AssetHandle.h"

// StreamingRequest descreve uma solicitação de carregamento assíncrono.
//
// Melhorias em relação à versão anterior:
//   - Include de AssetHandle.h presente
//   - DistrictID: identifica a qual região o request pertence —
//     o FutureStreamingManager pode cancelar todos os requests de um
//     distrito ao fazer unload da região

struct StreamingRequest
{
    AssetHandle Handle;
    float       Priority    = 1.0f;
    uint32_t    DistrictID  = 0;    // 0 = global
    bool        bImmediate  = false;
};