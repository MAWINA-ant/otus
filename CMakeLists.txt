cmake_minimum_required(VERSION 3.5)

project(command_parser VERSION 1.1.1)

add_executable(command_parser main.cpp
                                command.h
                                command.cpp)

set_target_properties(command_parser PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME "bulk"
)

install(TARGETS command_parser RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT chaika1201@gmail.com)

include(CPack)

