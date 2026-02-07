#pragma once

#include "ICommandHandler.h"
#include "SystemState.h"

class GetModeHandler : public ICommandHandler {
    public:
        explicit GetModeHandler(SystemState& state);
        CommandResult handle(const Command& command) override;

    private:
        SystemState& state_;
};