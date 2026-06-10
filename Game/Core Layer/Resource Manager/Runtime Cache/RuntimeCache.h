#pragma once

#include <unordered_map>

class RuntimeCache
{
public:

    void Add(
        AssetID ID,
        void* Data
    );

    void Remove(
        AssetID ID
    );

    void* Find(
        AssetID ID
    );

private:

    std::unordered_map<
        AssetID,
        void*
    > CachedAssets;
};
