#pragma once

#include <string>

class SystemState {
    public:
        SystemState();

        const std::string& mode() const;
        void setMode(const std::string& mode);
        void reset();

    private:
        std::string mode_;
};