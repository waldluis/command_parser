#include "CommandParser.h"
#include <sstream>
#include <algorithm>
#include <cctype>


std::optional<Command> CommandParser::parse(const std::string &input, CommandResult &errorResult)
{
    // trim leading and trailing whitespaces
    std::string cleaned = trim(input);

    // check if empty
    if(cleaned.empty()) {
        errorResult = CommandResult::failure("Empty Command");
        return std::nullopt;
    }

    // Split by whitespace
    std::vector<std::string> arguments;
    std::istringstream iss(cleaned);
    std::string token;

    if(!(iss >> token)) {
        errorResult = CommandResult::failure("Failed to parse command");
        return std::nullopt;
    }


    // first token = command name and convert to upper
    std::string command = to_upper(token);

    // Remaining tokens = arguments
    while (iss >> token) {
        arguments.push_back(token);
    }

    errorResult = CommandResult::success("Command parsed successfully");
    
    Command cmd = Command(command_type_from_string(command), arguments);
    
    return cmd;
}

std::string CommandParser::trim(const std::string &line)
{
    const char* white_space = " \t\r\n";
    std::size_t start = line.find_first_not_of(white_space);
    std::size_t end = line.find_last_not_of(white_space);
    return start == end ? std::string() : line.substr(start, end - start + 1);
}

std::string CommandParser::to_upper(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });
    return s;
}
