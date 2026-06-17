#pragma once

#include <unordered_map>

class SerializationRegistry
{
public:

    void RegisterType(
        const char* TypeName
    );

private:

    std::unordered_map
    <
        std::string,
        uint32_t
    > RegisteredTypes;
};