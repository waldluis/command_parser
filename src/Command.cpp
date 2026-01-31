#include "Command.h"

Command::Command(CommandType type, std::vector<std::string> arguments)
    : type_(type), arguments_(std::move(arguments))
{
}

CommandType Command::type() const
{
    return type_;
}

const std::vector<std::string> &Command::arguments() const
{
    return arguments_;
}

bool Command::operator==(const Command &other) const
{
    return type_ == other.type_ && arguments_ == other.arguments_;
}

bool Command::operator!=(const Command &other) const
{
    return type_ != other.type_ || arguments_ != other.arguments_;
}
