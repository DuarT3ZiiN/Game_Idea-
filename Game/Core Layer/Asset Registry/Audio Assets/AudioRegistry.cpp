#include "AudioRegistry.h"

void AudioRegistry::RegisterAudioAsset(
    const AudioAsset& Asset
)
{
    Assets[Asset.ID] = Asset;
}

const AudioAsset*
AudioRegistry::FindAudioAsset(
    AssetID ID
) const
{
    auto It =
        Assets.find(ID);

    if (It == Assets.end())
    {
        return nullptr;
    }

    return &It->second;
}
