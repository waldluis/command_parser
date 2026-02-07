#include "CommandResult.h"

// CommandResult::CommandResult(bool success, std::string message) 
//     : success_(success), message_(std::move(message))
// {
// }

CommandResult::CommandResult(bool success, std::string message) {
    success_ = success;
    message_ = message;
}

CommandResult CommandResult::success(const std::string &message)
{
    return CommandResult(true, message);
}

CommandResult CommandResult::failure(const std::string &message)
{
    return CommandResult(false, message);
}

bool CommandResult::isSuccess() const
{
    return success_;
}

const std::string &CommandResult::message() const
{
    return message_;
}

bool CommandResult::operator==(const CommandResult &other) const
{
    return success_ == other.success_ && message_ == other.message_;
}

bool CommandResult::operator!=(const CommandResult &other) const
{
    return success_ != other.success_ || message_ != other.message_;
}
