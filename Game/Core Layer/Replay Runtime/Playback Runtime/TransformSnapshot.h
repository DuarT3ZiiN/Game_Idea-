#pragma once

struct Vector3
{
    float X = 0.0f;
    float Y = 0.0f;
    float Z = 0.0f;
};

struct Quaternion
{
    float X = 0.0f;
    float Y = 0.0f;
    float Z = 0.0f;
    float W = 1.0f;
};

struct TransformSnapshot
{
    Vector3 Position;

    Quaternion Rotation;
};
