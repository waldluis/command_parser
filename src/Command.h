#pragma once

#include <string>
#include <vector>

enum class CommandType {
    SET,
    GET,
    RESET,
    INVALID
};

class Command {
public:
    Command(CommandType type, std::vector<std::string> arguments);

    CommandType type() const;
    const std::vector<std::string>& arguments() const;

    bool operator==(const Command & other) const;
    bool operator!=(const Command & other) const;

private:
    CommandType type_;
    std::vector<std::string> arguments_;
};