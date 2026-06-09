#pragma once

// Tipos matemáticos standalone para o protótipo C++ puro.
// Ao migrar para UE5: substituir Vector3 por FVector e Quaternion por FQuat.
// Os aliases abaixo permitem fazer essa troca em um único lugar.

struct Vector3
{
    float X = 0.f;
    float Y = 0.f;
    float Z = 0.f;

    Vector3 operator+(const Vector3& Other) const
    {
        return { X + Other.X, Y + Other.Y, Z + Other.Z };
    }

    Vector3 operator*(float Scalar) const
    {
        return { X * Scalar, Y * Scalar, Z * Scalar };
    }

    Vector3& operator+=(const Vector3& Other)
    {
        X += Other.X; Y += Other.Y; Z += Other.Z;
        return *this;
    }
};

struct Quaternion
{
    float X = 0.f;
    float Y = 0.f;
    float Z = 0.f;
    float W = 1.f;
};

struct TransformSnapshot
{
    Vector3    Position;
    Quaternion Rotation;
    Vector3    Scale    = { 1.f, 1.f, 1.f };
};