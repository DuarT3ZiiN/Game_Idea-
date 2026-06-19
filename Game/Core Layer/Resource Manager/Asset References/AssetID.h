#pragma once

// AssetID do Resource Manager — mesmo tipo do Asset Registry.
// Incluir diretamente do Asset Registry se ambos os módulos
// estiverem no mesmo projeto para evitar redefinição de tipo.
// Mantido aqui para que o Resource Manager compile standalone.

#include <cstdint>
#include <atomic>

using AssetID = uint64_t;

static constexpr AssetID INVALID_ASSET_ID = 0;