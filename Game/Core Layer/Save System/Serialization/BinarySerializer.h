#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <cstring>

// BinarySerializer — serialização binária de tipos POD e containers.
//
// Melhorias em relação à versão anterior:
//   - WriteString / ReadString: prefixo uint32_t de tamanho + bytes
//     (a versão anterior usava reinterpret_cast em std::string — UB e corrupção garantida)
//   - WriteVector / ReadVector: serializa tamanho + elementos
//   - Crc32(): calcula checksum do buffer para validação ao carregar
//   - Write<T> e Read<T> mantidos para tipos POD triviais

class BinarySerializer
{
public:

    // ── POD trivial ───────────────────────────────────────────────────────

    template<typename T>
    static void Write(std::ofstream& Stream, const T& Data)
    {
        static_assert(
            std::is_trivially_copyable<T>::value,
            "Use WriteString ou WriteVector para tipos não-POD"
        );
        Stream.write(reinterpret_cast<const char*>(&Data), sizeof(T));
    }

    template<typename T>
    static void Read(std::ifstream& Stream, T& Data)
    {
        static_assert(
            std::is_trivially_copyable<T>::value,
            "Use ReadString ou ReadVector para tipos não-POD"
        );
        Stream.read(reinterpret_cast<char*>(&Data), sizeof(T));
    }

    // ── std::string ───────────────────────────────────────────────────────

    static void WriteString(std::ofstream& Stream, const std::string& Str)
    {
        const uint32_t Len = static_cast<uint32_t>(Str.size());
        Stream.write(reinterpret_cast<const char*>(&Len), sizeof(Len));
        Stream.write(Str.data(), Len);
    }

    static void ReadString(std::ifstream& Stream, std::string& Str)
    {
        uint32_t Len = 0;
        Stream.read(reinterpret_cast<char*>(&Len), sizeof(Len));
        Str.resize(Len);
        Stream.read(Str.data(), Len);
    }

    // ── std::vector<T> com T trivialmente copiável ────────────────────────

    template<typename T>
    static void WriteVector(std::ofstream& Stream, const std::vector<T>& Vec)
    {
        const uint32_t Count = static_cast<uint32_t>(Vec.size());
        Stream.write(reinterpret_cast<const char*>(&Count), sizeof(Count));
        if (Count > 0)
            Stream.write(
                reinterpret_cast<const char*>(Vec.data()),
                Count * sizeof(T)
            );
    }

    template<typename T>
    static void ReadVector(std::ifstream& Stream, std::vector<T>& Vec)
    {
        uint32_t Count = 0;
        Stream.read(reinterpret_cast<char*>(&Count), sizeof(Count));
        Vec.resize(Count);
        if (Count > 0)
            Stream.read(
                reinterpret_cast<char*>(Vec.data()),
                Count * sizeof(T)
            );
    }

    // ── CRC32 (FNV-1a sobre buffer de bytes) ──────────────────────────────

    static uint32_t Crc32(const void* Data, size_t Size)
    {
        const uint8_t* Bytes = static_cast<const uint8_t*>(Data);
        uint32_t       Hash  = 2166136261u;

        for (size_t i = 0; i < Size; ++i)
        {
            Hash ^= Bytes[i];
            Hash *= 16777619u;
        }

        return Hash;
    }
};