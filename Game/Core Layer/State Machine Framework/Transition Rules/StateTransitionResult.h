#pragma once

enum class EStateTransitionResult : uint8_t
{
    Success,
    InvalidState,
    IllegalTransition,
    Blocked
};