#pragma once

#include <vector>
#include <string>

#include "AssetID.h"
#include "VehicleRegistry.h"
#include "WorldRegistry.h"
#include "AudioRegistry.h"

// AssetQuery expõe queries de alto nível sobre os três registries.
//
// Melhoria em relação à versão anterior:
//   - A versão anterior tinha as assinaturas mas sem nenhuma referência
//     aos registries — impossível implementar sem acesso a eles
//   - Agora recebe ponteiros para os registries no Initialize()
//   - Cada método delega para o registry correto

class AssetQuery
{
public:

    void Initialize(
        const VehicleRegistry* InVehicles,
        const WorldRegistry*   InWorld,
        const AudioRegistry*   InAudio
    );

    std::vector<AssetID> FindVehiclesByBrand(const std::string& Brand) const;

    std::vector<AssetID> FindDistrictAssets(uint32_t DistrictID) const;

    std::vector<AssetID> FindEngineSounds(AssetID VehicleID) const;

private:

    const VehicleRegistry* Vehicles = nullptr;
    const WorldRegistry*   World    = nullptr;
    const AudioRegistry*   Audio    = nullptr;
};