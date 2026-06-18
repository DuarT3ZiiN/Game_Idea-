#pragma once

#include <string>

class ProfilerScope
{
public:

    explicit ProfilerScope(
        const std::string& Name
    );

    ~ProfilerScope();

private:

    std::string ScopeName;

    PerformanceCounter Counter;
};
