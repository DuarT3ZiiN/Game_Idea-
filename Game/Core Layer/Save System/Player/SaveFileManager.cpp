#include "SaveFileManager.h"
#include "BinarySerializer.h"

#include <fstream>
#include <cstdio>   // std::rename

std::string SaveFileManager::GetSavePath(SaveSlotID Slot)
{
    return "SaveSlot_" + std::to_string(Slot) + ".sav";
}

bool SaveFileManager::FileExists(const std::string& Path) const
{
    std::ifstream F(Path);
    return F.good();
}

// ── Serialização ─────────────────────────────────────────────────────────────

void SaveFileManager::SerializeSaveGame(
    std::ofstream& Stream,
    const SaveGame& Save
)
{
    // Metadata (campos POD + strings)
    BinarySerializer::Write      (Stream, Save.Metadata.SlotID);
    BinarySerializer::WriteString(Stream, Save.Metadata.SaveName);
    BinarySerializer::Write      (Stream, Save.Metadata.UnixTimestamp);
    BinarySerializer::Write      (Stream, Save.Metadata.PlayTimeSeconds);
    BinarySerializer::Write      (Stream, Save.Metadata.Version);
    BinarySerializer::Write      (Stream, Save.Metadata.Checksum); // escrito como 0, atualizado após

    // PlayerSaveData
    BinarySerializer::WriteString(Stream, Save.Player.PlayerName);
    BinarySerializer::Write      (Stream, Save.Player.Money);
    BinarySerializer::Write      (Stream, Save.Player.Reputation);
    BinarySerializer::Write      (Stream, Save.Player.Level);
    BinarySerializer::Write      (Stream, Save.Player.HeatLevel);
    BinarySerializer::Write      (Stream, Save.Player.ActiveVehicleID);
    BinarySerializer::Write      (Stream, Save.Player.CurrentDistrictID);
    BinarySerializer::WriteVector(Stream, Save.Player.OwnedCars);
    BinarySerializer::WriteVector(Stream, Save.Player.UnlockedEvents);
    BinarySerializer::WriteVector(Stream, Save.Player.CompletedEvents);

    // WorldSaveData
    BinarySerializer::Write      (Stream, Save.World.WorldSeed);
    BinarySerializer::Write      (Stream, Save.World.WorldTimeMS);
    BinarySerializer::WriteVector(Stream, Save.World.Districts);
    BinarySerializer::WriteVector(Stream, Save.World.Rivals);

    // GarageSaveData — veículos têm vetor interno, serializa manualmente
    const uint32_t VehicleCount =
        static_cast<uint32_t>(Save.Garage.Vehicles.size());

    BinarySerializer::Write(Stream, VehicleCount);

    for (const auto& V : Save.Garage.Vehicles)
    {
        BinarySerializer::Write      (Stream, V.VehicleID);
        BinarySerializer::Write      (Stream, V.VehicleClass);
        BinarySerializer::Write      (Stream, V.Mileage);
        BinarySerializer::Write      (Stream, V.Damage);
        BinarySerializer::Write      (Stream, V.PerformanceLevel);
        BinarySerializer::Write      (Stream, V.PaintColorID);
        BinarySerializer::Write      (Stream, V.NitroLevel);
        BinarySerializer::WriteVector(Stream, V.InstalledParts);
    }
}

bool SaveFileManager::DeserializeSaveGame(
    std::ifstream& Stream,
    SaveGame&      Save
)
{
    BinarySerializer::Read      (Stream, Save.Metadata.SlotID);
    BinarySerializer::ReadString(Stream, Save.Metadata.SaveName);
    BinarySerializer::Read      (Stream, Save.Metadata.UnixTimestamp);
    BinarySerializer::Read      (Stream, Save.Metadata.PlayTimeSeconds);
    BinarySerializer::Read      (Stream, Save.Metadata.Version);
    BinarySerializer::Read      (Stream, Save.Metadata.Checksum);

    BinarySerializer::ReadString(Stream, Save.Player.PlayerName);
    BinarySerializer::Read      (Stream, Save.Player.Money);
    BinarySerializer::Read      (Stream, Save.Player.Reputation);
    BinarySerializer::Read      (Stream, Save.Player.Level);
    BinarySerializer::Read      (Stream, Save.Player.HeatLevel);
    BinarySerializer::Read      (Stream, Save.Player.ActiveVehicleID);
    BinarySerializer::Read      (Stream, Save.Player.CurrentDistrictID);
    BinarySerializer::ReadVector(Stream, Save.Player.OwnedCars);
    BinarySerializer::ReadVector(Stream, Save.Player.UnlockedEvents);
    BinarySerializer::ReadVector(Stream, Save.Player.CompletedEvents);

    BinarySerializer::Read      (Stream, Save.World.WorldSeed);
    BinarySerializer::Read      (Stream, Save.World.WorldTimeMS);
    BinarySerializer::ReadVector(Stream, Save.World.Districts);
    BinarySerializer::ReadVector(Stream, Save.World.Rivals);

    uint32_t VehicleCount = 0;
    BinarySerializer::Read(Stream, VehicleCount);
    Save.Garage.Vehicles.resize(VehicleCount);

    for (auto& V : Save.Garage.Vehicles)
    {
        BinarySerializer::Read      (Stream, V.VehicleID);
        BinarySerializer::Read      (Stream, V.VehicleClass);
        BinarySerializer::Read      (Stream, V.Mileage);
        BinarySerializer::Read      (Stream, V.Damage);
        BinarySerializer::Read      (Stream, V.PerformanceLevel);
        BinarySerializer::Read      (Stream, V.PaintColorID);
        BinarySerializer::Read      (Stream, V.NitroLevel);
        BinarySerializer::ReadVector(Stream, V.InstalledParts);
    }

    return Stream.good();
}

// ── I/O de disco ─────────────────────────────────────────────────────────────

ESaveResult SaveFileManager::SaveToDisk(
    const SaveGame&    Save,
    const std::string& Path
)
{
    // Escreve em arquivo temporário e renomeia atomicamente.
    // Se o processo morrer no meio, o save original permanece intacto.
    const std::string TmpPath = Path + ".tmp";

    std::ofstream File(TmpPath, std::ios::binary | std::ios::trunc);

    if (!File.is_open())
        return ESaveResult::FileWriteError;

    SerializeSaveGame(File, Save);

    if (!File.good())
        return ESaveResult::FileWriteError;

    File.close();

    // Renomeação atômica
    if (std::rename(TmpPath.c_str(), Path.c_str()) != 0)
        return ESaveResult::FileWriteError;

    return ESaveResult::Success;
}

ESaveResult SaveFileManager::LoadFromDisk(
    SaveGame&          Save,
    const std::string& Path
)
{
    std::ifstream File(Path, std::ios::binary);

    if (!File.is_open())
        return ESaveResult::FileNotFound;

    if (!DeserializeSaveGame(File, Save))
        return ESaveResult::FileReadError;

    return ESaveResult::Success;
}