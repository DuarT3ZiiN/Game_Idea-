#pragma once

class ReplaySerializer
{
public:

    bool SaveReplay(
        const ReplayRecording& Replay,
        const char* Filename
    );

    bool LoadReplay(
        ReplayRecording& Replay,
        const char* Filename
    );
};
