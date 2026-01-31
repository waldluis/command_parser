#include <gtest/gtest.h>
#include "Command.h"

TEST(CommandTest, CanCreateCommandWithType) {
    Command cmd(CommandType::SET, {});
    EXPECT_EQ(cmd.type(), CommandType::SET);
}

TEST(CommandTest, StoresArgumentsInOrder)
{
    Command cmd(CommandType::SET, {"MODE", "AUTO"});

    ASSERT_EQ(cmd.arguments().size(), 2u);
    EXPECT_EQ(cmd.arguments()[0], "MODE");
    EXPECT_EQ(cmd.arguments()[1], "AUTO");
}

TEST(CommandTest, CommandsWithSameContentAreEqual)
{
    Command a(CommandType::GET, {"MODE"});
    Command b(CommandType::GET, {"MODE"});

    EXPECT_EQ(a, b);
}

TEST(CommandTest, DifferentCommandsAreNotEqual)
{
    Command a(CommandType::RESET, {});
    Command b(CommandType::SET, {"MODE", "AUTO"});

    EXPECT_NE(a, b);
}