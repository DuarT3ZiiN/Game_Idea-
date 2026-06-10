#pragma once

#include <vector>

struct AssetDependency
{
    AssetID Parent;

    AssetID Child;
};

class DependencyResolver
{
public:

    void AddDependency(
        AssetID Parent,
        AssetID Child
    );

private:

    std::vector<
        AssetDependency
    > Dependencies;
};
