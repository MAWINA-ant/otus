cmake_minimum_required(VERSION 3.5)

project(allocator_container VERSION 1.1.1)

add_executable(allocator_container main.cpp)

set_target_properties(allocator_container  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

install(TARGETS allocator_container RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT chaika1201@gmail.com)

include(CPack)

