#pragma once

#include <fstream>
#include <string>

class BinarySerializer
{
public:

    template<typename T>
    static void Write(
        std::ofstream& Stream,
        const T& Data
    )
    {
        Stream.write(
            reinterpret_cast<
                const char*
            >(&Data),
            sizeof(T)
        );
    }

    template<typename T>
    static void Read(
        std::ifstream& Stream,
        T& Data
    )
    {
        Stream.read(
            reinterpret_cast<
                char*
            >(&Data),
            sizeof(T)
        );
    }
};


