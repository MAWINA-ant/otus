cmake_minimum_required(VERSION 3.5)

project(mvc_prototype VERSION 1.1.1)

add_executable(mvc_prototype main.cpp
                             model.cpp
                             view.cpp
                             controller.cpp
                             observ.h
                             model.h
                             view.h
                             controller.h
                         )

set_target_properties(mvc_prototype  PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

install(TARGETS mvc_prototype RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT chaika1201@gmail.com)

include(CPack)

