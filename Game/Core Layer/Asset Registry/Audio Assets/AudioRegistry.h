#pragma once

#include <unordered_map>

class AudioRegistry
{
public:

    void RegisterAudioAsset(
        const AudioAsset& Asset
    );

    const AudioAsset*
    FindAudioAsset(
        AssetID ID
    ) const;

private:

    std::unordered_map
    <
        AssetID,
        AudioAsset
    > Assets;
};