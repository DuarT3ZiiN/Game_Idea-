#pragma once

#include "SaveVersion.h"
#include "SaveTypes.h"

struct SaveGame;

class SaveVersionManager
{
public:

    static SaveVersion GetCurrentVersion();

    // Retorna Success se Major == atual, VersionIncompatible se incompatível,
    // VersionUpgraded se minor/build antigo e conseguiu migrar.
    static ESaveResult CheckCompatibility(const SaveVersion& FileVersion);

    // Tenta migrar um SaveGame de versão antiga para a atual.
    // Retorna false se a migração não for possível (Major incompatível).
    static bool Migrate(SaveGame& Save, const SaveVersion& FromVersion);
};