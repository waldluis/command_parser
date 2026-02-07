#include <gtest/gtest.h>

#include "SetModeHandler.h"
#include "GetModeHandler.h"
#include "ResetHandler.h"
#include "ResetHandler.h"
#include "Command.h"

TEST(HandlersTest, SetModeHandlerSetsState) {
    SystemState state;
    SetModeHandler handler(state);

    Command cmd(CommandType::SET, {"ACTIVE"});

    auto result = handler.handle(cmd);

    EXPECT_TRUE(result.isSuccess());
    EXPECT_EQ(state.mode(), "ACTIVE");
    EXPECT_EQ(result.message(), "Mode set to ACTIVE");
}

TEST(HandlersTest, SetModeHandlerFailsWithoutArgument) {
    SystemState state;
    SetModeHandler handler(state);

    Command cmd(CommandType::SET, {});

    auto result = handler.handle(cmd);

    EXPECT_FALSE(result.isSuccess());
    EXPECT_EQ(result.message(), "Missing mode argument");
}

TEST(HandlersTest, GetModeHandlerReturnsCurrentMode) {
    SystemState state;
    state.setMode("RUN");
    GetModeHandler handler(state);

    Command cmd(CommandType::GET, {});

    auto result = handler.handle(cmd);

    EXPECT_TRUE(result.isSuccess());
    EXPECT_EQ(result.message(), "RUN");
}

TEST(HandlersTest, ResetHandlerResetsState) {
    SystemState state;
    state.setMode("ERROR");
    ResetHandler handler(state);

    Command cmd(CommandType::RESET, {});

    auto result = handler.handle(cmd);

    EXPECT_TRUE(result.isSuccess());
    EXPECT_EQ(state.mode(), "IDLE");
    EXPECT_EQ(result.message(), "System reset");
}
