#pragma once

#include <fstream>

// ISerializable define a interface de serialização para qualquer struct
// que precise de lógica customizada além do BinarySerializer genérico.
//
// Correção em relação à versão anterior:
//   - Serialize / Deserialize recebem o stream por referência
//     (a versão anterior tinha assinatura vazia — inutilizável)

class ISerializable
{
public:

    virtual ~ISerializable() = default;

    virtual void Serialize  (std::ofstream& Stream) const = 0;
    virtual void Deserialize(std::ifstream& Stream)       = 0;
};