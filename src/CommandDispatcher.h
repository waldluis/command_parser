#pragma once

#include <map>
#include "Command.h"
#include "ICommandHandler.h"
#include "CommandResult.h"

class CommandDispatcher {
    public:
        void registerHandler(CommandType type, ICommandHandler* handler);
        CommandResult dispatch(const Command& command) const;

    private:
        std::map<CommandType, ICommandHandler*> handlers_;
};