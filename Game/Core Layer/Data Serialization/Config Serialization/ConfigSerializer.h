#pragma once

class ConfigSerializer
{
public:

    bool LoadConfig(
        const char* Filename,
        ConfigFile& Config
    );

    bool SaveConfig(
        const char* Filename,
        const ConfigFile& Config
    );
};