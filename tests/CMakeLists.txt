include(FetchContent)

# ---- GoogleTest ----
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ---- Test executable ----
add_executable(command_parser_tests
    CommandTest.cpp
    CommandResultTest.cpp
    CommandParserTest.cpp
)

target_link_libraries(command_parser_tests
    PRIVATE
        command_parser_lib
        gtest
        gtest_main
        gmock
)

include(GoogleTest)
gtest_discover_tests(command_parser_tests)