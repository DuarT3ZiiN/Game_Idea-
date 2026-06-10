#pragma once

struct StreamingRequest
{
    AssetHandle Asset;

    float Priority = 1.0f;

    bool Immediate = false;
};
