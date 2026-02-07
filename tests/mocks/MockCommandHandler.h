#pragma once

#include <gmock/gmock.h>
#include "ICommandHandler.h"

class MockCommandHandler : public ICommandHandler {
    public:
        MOCK_METHOD(CommandResult, handle, (const Command& command), (override));
};