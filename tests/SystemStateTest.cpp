#include <gtest/gtest.h>

#include "SystemState.h"

TEST(SystemState, DefaultModeIsIdle) {
    SystemState state;
    EXPECT_EQ(state.mode(), "IDLE");
}

TEST(SystemState, SetModeActive) {
    SystemState state;
    state.setMode("ACTIVE");
    EXPECT_EQ(state.mode(), "ACTIVE");
}

TEST(SystemState, ResetDefaultMode) {
    SystemState state;
    state.setMode("ERROR");
    state.reset();
    EXPECT_EQ(state.mode(), "IDLE");
}