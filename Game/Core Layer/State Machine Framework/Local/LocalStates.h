#pragma once

enum class ELocalState : uint8_t
{
    None,

    Countdown,

    DriftChain,

    SearchMode,

    NitroActive,

    PoliceEscalation
};