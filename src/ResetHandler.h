#pragma once

#include "ICommandHandler.h"
#include "SystemState.h"

class ResetHandler : public ICommandHandler {
    public:
        explicit ResetHandler(SystemState& state);
        CommandResult handle(const Command& command) override;

    private:
        SystemState& state_;
};