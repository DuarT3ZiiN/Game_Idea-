#include "BinaryWriter.h"

BinaryWriter::BinaryWriter(
    const char* Filename
)
{
    File.open(
        Filename,
        std::ios::binary
    );
}

BinaryWriter::~BinaryWriter()
{
    if (File.is_open())
    {
        File.close();
    }
}

bool BinaryWriter::IsOpen() const
{
    return File.is_open();
}

