#pragma once

class AssetRegistryManager;

// AssetRegistryLoader popula os registries a partir de disco/config.
//
// Melhorias em relação à versão anterior:
//   - Recebe referência ao AssetRegistryManager — a versão anterior
//     tinha métodos void sem acesso a nenhum registry
//   - Retorna bool para indicar sucesso de carregamento
//   - LoadAll() carrega os três registries em sequência

class AssetRegistryLoader
{
public:

    void Initialize(AssetRegistryManager* InManager);

    bool LoadAll();

    bool LoadVehicleRegistry();

    bool LoadWorldRegistry();

    bool LoadAudioRegistry();

private:

    AssetRegistryManager* Manager = nullptr;
};