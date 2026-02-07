#include "GetModeHandler.h"

GetModeHandler::GetModeHandler(SystemState &state): state_(state)
{
}

CommandResult GetModeHandler::handle(const Command &command)
{
    return CommandResult::success(state_.mode());
}
