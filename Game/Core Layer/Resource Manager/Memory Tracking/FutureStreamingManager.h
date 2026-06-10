#pragma once

class StreamingManager
{
public:

    void RequestAsset(
        const StreamingRequest&
        Request
    );

    void Update();
};