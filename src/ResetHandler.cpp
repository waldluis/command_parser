#include "ResetHandler.h"

ResetHandler::ResetHandler(SystemState &state): state_(state)
{
}

CommandResult ResetHandler::handle(const Command &command)
{
    state_.reset();
    return CommandResult::success("System reset");
}
