#pragma once

#include <fstream>

class BinaryWriter
{
public:

    explicit BinaryWriter(
        const char* Filename
    );

    ~BinaryWriter();

    template<typename T>
    void Write(
        const T& Value
    )
    {
        File.write(
            reinterpret_cast<
                const char*
            >(&Value),
            sizeof(T)
        );
    }

    bool IsOpen() const;

private:

    std::ofstream File;
};


