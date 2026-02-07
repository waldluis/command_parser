#pragma once

#include "Command.h"
#include "CommandResult.h"

class ICommandHandler {
    public:
        virtual ~ICommandHandler() = default;
        virtual CommandResult handle(const Command& command) = 0;
};