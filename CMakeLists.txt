cmake_minimum_required(VERSION 3.26)
project(EQUtilities LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ENV{PATH} "C:/Qt/6.8.1/msvc2022_64/bin;$ENV{PATH}")
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/msvc2022_64")
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_library( STATIC
    businesslogic.cpp
)

qt_add_executable(EQUtilitiesTests
    tests/EQTests.hpp
    tests/EQTests.cpp
    tests/main.cpp
)
target_link_libraries(EQUtilities PRIVATE Qt6::Widgets)
set_target_properties(EQUtilities PROPERTIES
    WIN32_EXECUTABLE ON
)
