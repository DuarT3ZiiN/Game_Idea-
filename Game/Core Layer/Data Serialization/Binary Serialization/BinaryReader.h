#pragma once

#include <fstream>

class BinaryReader
{
public:

    explicit BinaryReader(
        const char* Filename
    );

    ~BinaryReader();

    template<typename T>
    void Read(
        T& Value
    )
    {
        File.read(
            reinterpret_cast<
                char*
            >(&Value),
            sizeof(T)
        );
    }

    bool IsOpen() const;

private:

    std::ifstream File;
};