#pragma once

#include <vector>
#include <unordered_map>

#include "AssetID.h"

// DependencyResolver rastreia dependências entre assets.
// Quando um District é carregado, o ResourceManager precisa saber
// quais assets de malha, textura e áudio ele depende para pré-carregar.
//
// Melhorias em relação à versão anterior:
//   - Include de AssetID.h presente (versão anterior usava AssetID sem include)
//   - GetDependencies(ParentID) — retorna lista de filhos diretos
//   - Clear() — reseta entre sessões

struct AssetDependency
{
    AssetID Parent = INVALID_ASSET_ID;
    AssetID Child  = INVALID_ASSET_ID;
};

class DependencyResolver
{
public:

    void AddDependency(AssetID Parent, AssetID Child);

    // Retorna todos os assets que Parent depende diretamente
    const std::vector<AssetID>& GetDependencies(AssetID Parent) const;

    bool HasDependencies(AssetID Parent) const;

    void Clear();

private:

    std::unordered_map<AssetID, std::vector<AssetID>> DependencyMap;

    // Retornado por referência quando Parent não tem dependências
    static const std::vector<AssetID> EmptyList;
};