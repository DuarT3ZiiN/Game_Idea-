#pragma once

class StreamingDebugManager
{
public:

    void SetMode(
        EStreamingDebugMode Mode
    );

    void Draw();

private:

    EStreamingDebugMode CurrentMode =
        EStreamingDebugMode::None;

    StreamingStatistics Stats;
};
