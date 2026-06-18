#include "ProfilerScope.h"

ProfilerScope::ProfilerScope(
    const std::string& Name
)
    : ScopeName(Name)
{
    Counter.Begin();
}

ProfilerScope::~ProfilerScope()
{
    Counter.End();

    // enviar para profiler
}