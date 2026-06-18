#pragma once

#include <unordered_map>
#include <vector>
#include <string>

#include "VehicleAsset.h"

// VehicleRegistry armazena e indexa os assets de veículo.
//
// Melhorias em relação à versão anterior:
//   - FindByManufacturer() — necessário para a UI de garagem filtrar por marca
//   - FindByClass() — necessário para eventos restringirem entrada por classe
//   - UnregisterVehicle() — permite retirar veículos do registry em runtime
//   - GetAll() — iteração completa para inicialização e debug

class VehicleRegistry
{
public:

    void RegisterVehicle(const VehicleAsset& Asset);

    void UnregisterVehicle(AssetID ID);

    const VehicleAsset* FindVehicle(AssetID ID) const;

    std::vector<AssetID> FindByManufacturer(const std::string& Manufacturer) const;

    std::vector<AssetID> FindByClass(uint32_t PerformanceClass) const;

    const std::unordered_map<AssetID, VehicleAsset>& GetAll() const;

private:

    std::unordered_map<AssetID, VehicleAsset> Vehicles;
};