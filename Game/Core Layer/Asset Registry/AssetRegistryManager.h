#pragma once

#include "VehicleRegistry.h"
#include "WorldRegistry.h"
#include "AudioRegistry.h"
#include "AssetDataBaseQuery.h"

// AssetRegistryManager é o ponto central do Asset Registry.
//
// Melhorias em relação à versão anterior:
//   - Initialize() conecta o AssetQuery aos três registries
//   - GetQuery() expõe queries de alto nível sem expor os registries diretamente
//   - Accessors const adicionados para leitura sem modificação

class AssetRegistryManager
{
public:

    void Initialize();

    VehicleRegistry&       Vehicles();
    WorldRegistry&         World();
    AudioRegistry&         Audio();
    AssetQuery&            GetQuery();

    const VehicleRegistry& Vehicles() const;
    const WorldRegistry&   World()    const;
    const AudioRegistry&   Audio()    const;

private:

    VehicleRegistry VehicleAssets;
    WorldRegistry   WorldAssets;
    AudioRegistry   AudioAssets;
    AssetQuery      Query;
};