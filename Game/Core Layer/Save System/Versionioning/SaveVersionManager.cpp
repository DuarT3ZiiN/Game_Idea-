#include "SaveVersionManager.h"
#include "SaveGame.h"

SaveVersion SaveVersionManager::GetCurrentVersion()
{
    return { 1, 0, 0 };
}

ESaveResult SaveVersionManager::CheckCompatibility(
    const SaveVersion& FileVersion
)
{
    const SaveVersion Current = GetCurrentVersion();

    // Major diferente → incompatível, não podemos carregar
    if (FileVersion.Major != Current.Major)
        return ESaveResult::VersionIncompatible;

    // Minor ou Build mais antigos → migrável
    if (FileVersion < Current)
        return ESaveResult::VersionUpgraded;

    return ESaveResult::Success;
}

bool SaveVersionManager::Migrate(
    SaveGame&          Save,
    const SaveVersion& FromVersion
)
{
    // Major incompatível — não há migração possível
    if (FromVersion.Major != GetCurrentVersion().Major)
        return false;

    // Ponto de extensão: adicione aqui blocos de migração por versão.
    // Exemplo:
    //   if (FromVersion < SaveVersion{1, 1, 0})
    //   {
    //       Save.Player.HeatLevel = 0; // campo novo na 1.1.0
    //   }

    // Atualiza a versão do save após migração bem-sucedida
    Save.Metadata.Version = GetCurrentVersion();

    return true;
}