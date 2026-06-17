#pragma once

#include <unordered_map>

class RuntimeConfigManager
{
public:

    void LoadAll();

    void Reload();

private:

    std::unordered_map
    <
        std::string,
        ConfigFile
    > LoadedConfigs;
};