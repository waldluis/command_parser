#pragma once

#include <string>

class CommandResult {
public:
    static CommandResult success(const std::string& message);
    static CommandResult failure(const std::string& message);

    bool isSuccess() const;
    const std::string& message() const;

    bool operator==(const CommandResult& other) const;
    bool operator!=(const CommandResult& other) const;

private:
    CommandResult(bool success, std::string message);

    bool success_;
    std::string message_;
};