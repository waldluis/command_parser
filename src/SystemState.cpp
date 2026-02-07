#include "SystemState.h"

namespace {
    constexpr const char* DEFAULT_MODE = "IDLE";
}

SystemState::SystemState() : mode_(DEFAULT_MODE)
{
}

const std::string &SystemState::mode() const
{
    return mode_;
}

void SystemState::setMode(const std::string &mode)
{
    mode_ = mode;
}

void SystemState::reset()
{
    mode_ = DEFAULT_MODE;
}
