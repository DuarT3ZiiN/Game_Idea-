#include "BinaryReader.h"

BinaryReader::BinaryReader(
    const char* Filename
)
{
    File.open(
        Filename,
        std::ios::binary
    );
}

BinaryReader::~BinaryReader()
{
    if (File.is_open())
    {
        File.close();
    }
}

bool BinaryReader::IsOpen() const
{
    return File.is_open();
}