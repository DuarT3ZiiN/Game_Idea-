#include "AssetDependencies.h"

const std::vector<AssetID> DependencyResolver::EmptyList = {};

void DependencyResolver::AddDependency(AssetID Parent, AssetID Child)
{
    DependencyMap[Parent].push_back(Child);
}

const std::vector<AssetID>& DependencyResolver::GetDependencies(
    AssetID Parent
) const
{
    auto It = DependencyMap.find(Parent);
    return (It != DependencyMap.end()) ? It->second : EmptyList;
}

bool DependencyResolver::HasDependencies(AssetID Parent) const
{
    auto It = DependencyMap.find(Parent);
    return It != DependencyMap.end() && !It->second.empty();
}

void DependencyResolver::Clear()
{
    DependencyMap.clear();
}