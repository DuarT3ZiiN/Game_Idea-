#pragma once

#include <cstdint>

struct SaveVersion
{
    uint32_t Major = 1;
    uint32_t Minor = 0;
    uint32_t Build = 0;

    bool operator==(const SaveVersion& Other) const
    {
        return Major == Other.Major
            && Minor == Other.Minor
            && Build == Other.Build;
    }

    bool operator<(const SaveVersion& Other) const
    {
        if (Major != Other.Major) return Major < Other.Major;
        if (Minor != Other.Minor) return Minor < Other.Minor;
        return Build < Other.Build;
    }

    bool IsNewerThan(const SaveVersion& Other) const
    {
        return Other < *this;
    }
};