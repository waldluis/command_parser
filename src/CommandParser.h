#pragma once

#include <string>
#include <optional>
#include "Command.h"
#include "CommandResult.h"

class CommandParser {
public:
    static std::optional<Command> parse(const std::string& input, CommandResult& errorResult);

    static std::string trim(const std::string& line);
    static std::string to_upper(std::string s);
};