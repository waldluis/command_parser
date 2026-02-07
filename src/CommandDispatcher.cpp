#include "CommandDispatcher.h"

void CommandDispatcher::registerHandler(CommandType type, ICommandHandler *handler)
{
    handlers_[type] = handler;

}

CommandResult CommandDispatcher::dispatch(const Command &command) const
{
    auto it = handlers_.find(command.type());

    if (it == handlers_.end() || it->second == nullptr) {
        return CommandResult::failure("Unkown comand");
    }

    return it->second->handle(command);
}
