#include <gtest/gtest.h>
#include "CommandParser.h"

TEST(CommandParserTest, TrimWhitespaces)
{
    std::string line = CommandParser::trim("  Test  ");
    EXPECT_EQ(line, "Test");
}

TEST(CommandParserTest, TrimWhitespaces2)
{
    std::string line = CommandParser::trim("  Test Hallo  ");
    EXPECT_EQ(line, "Test Hallo");
}

TEST(CommandParserTest, EmptyInputFails)
{
    CommandResult error = CommandResult::failure("");;
    auto cmd = CommandParser::parse("   ", error);
    EXPECT_FALSE(cmd.has_value());
    EXPECT_FALSE(error.isSuccess());
}

TEST(CommandParserTest, ToUpper)
{
    std::string line = CommandParser::to_upper("Test Hallo");
    EXPECT_EQ(line, "TEST HALLO");
}

TEST(CommandParserTest, ParseSimpleCommand)
{
    CommandResult error = CommandResult::failure("");;
    auto cmd = CommandParser::parse("set", error);
    ASSERT_TRUE(cmd.has_value());
    EXPECT_TRUE(error.isSuccess());
    EXPECT_EQ(cmd->type(), CommandType::SET);
    EXPECT_TRUE(cmd->arguments().empty());
}

TEST(CommandParserTest, ParseCommandWithArgument)
{
    CommandResult error = CommandResult::failure("");;
    auto cmd = CommandParser::parse("set auto", error);
    ASSERT_TRUE(cmd.has_value());
    EXPECT_TRUE(error.isSuccess());
    EXPECT_EQ(cmd->type(), CommandType::SET);
    ASSERT_EQ(cmd->arguments().size(), 1);
    EXPECT_EQ(cmd->arguments()[0], "auto");
}
