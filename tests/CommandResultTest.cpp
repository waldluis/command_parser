#include <gtest/gtest.h>
#include "CommandResult.h"

TEST(CommandResultTest, SuccessResultIsSuccessful)
{
    CommandResult result = CommandResult::success("OK");

    EXPECT_TRUE(result.isSuccess());
    EXPECT_EQ(result.message(), "OK");
}

TEST(CommandResultTest, FailureResultIsNotSuccessful)
{
    CommandResult result = CommandResult::failure("ERROR");

    EXPECT_FALSE(result.isSuccess());
    EXPECT_EQ(result.message(), "ERROR");
}

TEST(CommandResultTest, SuccessAndFailureAreNotEqual)
{
    CommandResult ok = CommandResult::success("OK");
    CommandResult fail = CommandResult::failure("OK");

    EXPECT_NE(ok, fail);
}

TEST(CommandResultTest, ResultsWithSameContentAreEqual)
{
    CommandResult a = CommandResult::failure("Invalid command");
    CommandResult b = CommandResult::failure("Invalid command");

    EXPECT_EQ(a, b);
}