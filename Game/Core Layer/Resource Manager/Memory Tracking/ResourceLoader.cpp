#include "ResourceLoader.h"

ELoadResult ResourceLoader::Load(
    const AssetReference& Reference,
    void*&                OutData
)
{
    OutData = nullptr;

    if (Reference.Path.empty())
        return ELoadResult::FileNotFound;

    // TODO: carregamento real por tipo:
    //   EAssetType::Texture  → DDS loader
    //   EAssetType::Mesh     → FBX/binary mesh loader
    //   EAssetType::Sound    → OGG/WAV loader
    //   EAssetType::District → binary world loader
    //
    // Retorna Success com OutData = nullptr por ora (stub de carregamento)

    return ELoadResult::Success;
}

void ResourceLoader::Unload(AssetID ID, void* Data)
{
    // Libera memória do asset — quando o loader real alocar com new/malloc,
    // aqui deve chamar delete/free correspondente por tipo.
    (void)ID;

    if (Data)
    {
        // TODO: delete Data ou free(Data) baseado no tipo do asset
    }
}