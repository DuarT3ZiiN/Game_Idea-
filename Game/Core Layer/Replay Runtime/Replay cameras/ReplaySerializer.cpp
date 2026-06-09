#include "ReplaySerializer.h"
#include "BinarySerializer.h"

#include <fstream>
#include <cstring>
#include <cstdio>

bool ReplaySerializer::SaveReplay(
    const ReplayRecording& Recording,
    const char*            Filename
)
{
    if (Recording.GetFrameCount() == 0)
        return false;

    const std::string TmpPath = std::string(Filename) + ".tmp";

    std::ofstream File(TmpPath, std::ios::binary | std::ios::trunc);

    if (!File.is_open())
        return false;

    // Header
    BinarySerializer::Write(File, Recording.GetHeader());

    // Frames
    for (uint64_t i = 0; i < Recording.GetFrameCount(); ++i)
    {
        const ReplayFrame& Frame = Recording.GetFrame(i);

        BinarySerializer::Write(File, Frame.FrameID);
        BinarySerializer::Write(File, Frame.Timestamp);
        BinarySerializer::Write(File, Frame.Input);

        BinarySerializer::WriteVector(File, Frame.VehicleStates);
    }

    if (!File.good())
        return false;

    File.close();

    return std::rename(TmpPath.c_str(), Filename) == 0;
}

bool ReplaySerializer::LoadReplay(
    ReplayRecording& Recording,
    const char*      Filename
)
{
    std::ifstream File(Filename, std::ios::binary);

    if (!File.is_open())
        return false;

    // Valida MagicNumber antes de desserializar
    ReplayFileHeader Header;
    BinarySerializer::Read(File, Header);

    if (Header.MagicNumber != REPLAY_MAGIC_NUMBER)
        return false;

    Recording.GetHeader() = Header;

    for (uint64_t i = 0; i < Header.FrameCount; ++i)
    {
        ReplayFrame Frame;

        BinarySerializer::Read(File, Frame.FrameID);
        BinarySerializer::Read(File, Frame.Timestamp);
        BinarySerializer::Read(File, Frame.Input);
        BinarySerializer::ReadVector(File, Frame.VehicleStates);

        Recording.AddFrame(Frame);
    }

    return File.good();
}

const char* ReplaySerializer::GetDefaultPath(uint32_t SlotID)
{
    static char Buffer[64];
    std::snprintf(Buffer, sizeof(Buffer), "Replay_%u.replay", SlotID);
    return Buffer;
}