#pragma once

#include <vector>

struct ConfigSection
{
    std::string Name;

    std::vector<
        ConfigValue
    > Values;
};
