#include "SetModeHandler.h"

SetModeHandler::SetModeHandler(SystemState &state): state_(state)
{
}

CommandResult SetModeHandler::handle(const Command &command)
{
    const auto& args = command.arguments();

    if(args.empty()) {
        return CommandResult::failure("Missing mode argument");
    }

    state_.setMode(args[0]);
    return CommandResult::success("Mode set to " + state_.mode());
}
