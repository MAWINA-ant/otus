cmake_minimum_required(VERSION 3.2)

project(filter VERSION 1.1.1)

add_executable(filter_ip main.cpp)
add_library(utils utils.cpp)
add_executable(tests_google test_google.cpp)

set_target_properties(filter_ip utils tests_google  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(utils
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(filter_ip PRIVATE
    utils
)

target_link_libraries(tests_google gtest gmock pthread utils)

#target_compile_options(filter_ip PRIVATE
#        -Wall -Wextra -pedantic -Werror
#)
    
target_compile_options(utils PRIVATE
        -Wall -Wextra -pedantic -Werror
)
    
target_compile_options(tests_google PRIVATE
        -Wall -Wextra -pedantic -Werror
)

install(TARGETS filter_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(tests_google tests_google)
