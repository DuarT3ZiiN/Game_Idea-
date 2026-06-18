#pragma once

class GlobalConfigs
{
public:

    static ConfigRuntime&
    Get()
    {
        static ConfigRuntime Runtime;

        return Runtime;
    }
};
