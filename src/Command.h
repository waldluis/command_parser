#pragma once

#include <string>
#include <vector>
#include <algorithm>

enum class CommandType {
    SET,
    GET,
    RESET,
    INVALID
};

inline CommandType command_type_from_string(std::string s) {
    // normalize
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return std::toupper(c); });

    if (s == "SET")   return CommandType::SET;
    if (s == "GET")   return CommandType::GET;
    if (s == "RESET") return CommandType::RESET;

    return CommandType::INVALID;
}

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