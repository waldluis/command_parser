add_library(command_parser_lib
    Command.h
    Command.cpp
    CommandResult.h
    CommandResult.cpp
    CommandParser.h
    CommandParser.cpp
    CommandDispatcher.h
    CommandDispatcher.cpp
    ICommandHandler.h
    SystemState.h
    SystemState.cpp
    SetModeHandler.h
    SetModeHandler.cpp
    GetModeHandler.h
    GetModeHandler.cpp
    ResetHandler.h
    ResetHandler.cpp
    CommandProcessor.h
    CommandProcessor.cpp
)

target_include_directories(command_parser_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(command_parser
    main.cpp
)

target_link_libraries(command_parser
    PRIVATE command_parser_lib
)
