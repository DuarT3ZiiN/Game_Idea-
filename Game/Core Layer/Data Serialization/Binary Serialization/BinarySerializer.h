#pragma once

class BinarySerializer
{
public:

    template<typename T>
    static bool Save(
        const char* Filename,
        const T& Data
    )
    {
        BinaryWriter Writer(
            Filename
        );

        if (!Writer.IsOpen())
        {
            return false;
        }

        Writer.Write(Data);

        return true;
    }

    template<typename T>
    static bool Load(
        const char* Filename,
        T& Data
    )
    {
        BinaryReader Reader(
            Filename
        );

        if (!Reader.IsOpen())
        {
            return false;
        }

        Reader.Read(Data);

        return true;
    }
};

