#pragma once

#include <string>

#include "SaveGame.h"
#include "SaveTypes.h"

// SaveFileManager lida com a I/O de disco do save.
//
// Correções críticas em relação à versão anterior:
//   - SaveToDisk e LoadFromDisk NÃO usam mais reinterpret_cast em SaveGame
//     (SaveGame contém std::string e std::vector — não é POD, UB garantido)
//   - Agora usa BinarySerializer com WriteString/ReadString/WriteVector
//   - Retorna ESaveResult em vez de bool para diagnóstico de erros
//   - Salva em arquivo temporário e renomeia atomicamente (evita save corrompido
//     se o processo morrer no meio da escrita)

class SaveFileManager
{
public:

    ESaveResult SaveToDisk(
        const SaveGame&    Save,
        const std::string& Path
    );

    ESaveResult LoadFromDisk(
        SaveGame&          Save,
        const std::string& Path
    );

    bool FileExists(const std::string& Path) const;

    static std::string GetSavePath(SaveSlotID Slot);

private:

    // Serialização / deserialização tipada usando BinarySerializer
    void        SerializeSaveGame  (std::ofstream& Stream, const SaveGame& Save);
    bool        DeserializeSaveGame(std::ifstream& Stream, SaveGame& Save);
};