#pragma once

enum class EEventType : uint8_t
{
    Global,
    Local
};

enum class EEventPriority : uint8_t
{
    Critical,
    High,
    Normal,
    Background
};
