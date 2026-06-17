#include "ConfigSerializer.h"

bool ConfigSerializer::LoadConfig(
    const char* Filename,
    ConfigFile& Config
)
{
    // future:
    // JSON
    // YAML
    // TOML

    return true;
}

bool ConfigSerializer::SaveConfig(
    const char* Filename,
    const ConfigFile& Config
)
{
    return true;
}
