#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "mocks/MockCommandHandler.h"
#include "CommandDispatcher.h"

using ::testing::_;
using ::testing::Return;


TEST(CommandDispatcher, DispatchCallsCorrectHandler) {
    CommandDispatcher dispatcher;
    MockCommandHandler handler;

    Command cmd(CommandType::SET, {});

    dispatcher.registerHandler(CommandType::SET, &handler);

    EXPECT_CALL(handler, handle(_)).Times(1).WillOnce(Return(CommandResult::success("OK")));
    CommandResult result = dispatcher.dispatch(cmd);

    EXPECT_TRUE(result.isSuccess());
}

TEST(CommandDispatcher, UnknownCommandReturnsFailure) {
    CommandDispatcher dispatcher;
    Command cmd(CommandType::INVALID, {});

    CommandResult result = dispatcher.dispatch(cmd);

    EXPECT_FALSE(result.isSuccess());
}

TEST(CommandDispatcher, HandlerFailureIsPropagated) {
    CommandDispatcher dispatcher;
    MockCommandHandler handler;

    Command cmd(CommandType::RESET, {});

    dispatcher.registerHandler(CommandType::RESET, &handler);

    EXPECT_CALL(handler, handle(_)).Times(1).WillOnce(Return(CommandResult::failure("Reset failed")));
    CommandResult result = dispatcher.dispatch(cmd);

    EXPECT_FALSE(result.isSuccess());
    EXPECT_EQ(result.message(), "Reset failed");
}