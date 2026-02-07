#pragma once

#include "ICommandHandler.h"
#include "SystemState.h"

class SetModeHandler : public ICommandHandler {
    public:
        explicit SetModeHandler(SystemState& state);
        CommandResult handle(const Command& command) override;

    private:
        SystemState& state_;
};