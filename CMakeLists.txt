cmake_minimum_required(VERSION 3.26)
project(EQUtilities LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ENV{PATH} "C:/Qt/6.8.1/msvc2022_64/bin;$ENV{PATH}")
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/msvc2022_64")
add_compile_options(/EHsc)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

include(FetchContent)
FetchContent_Declare(
    EUtilities
    URL https://github.com/Force-quit/EUtilities/archive/refs/tags/v1.0.1.zip
)
FetchContent_MakeAvailable(EUtilities)

set(EQUTILITIES_SOURCE
    include/EQIntLineEdit.hpp
    src/EQIntLineEdit.cpp
    include/EQIntValidator.hpp
    src/EQIntValidator.cpp
    include/EQShortcutPicker.hpp
    src/EQShortcutPicker.cpp
    include/EQTextValidator.hpp
    src/EQTextValidator.cpp
    include/EQThread.hpp
)

qt_add_library(EQUtilities STATIC ${EQUTILITIES_SOURCE})
target_link_libraries(EQUtilities PRIVATE Qt6::Widgets EUtilities)
target_include_directories(EQUtilities PUBLIC include)

qt_add_executable(EQUtilitiesTests
    tests/EQTests.hpp
    tests/EQTests.cpp
    tests/main.cpp
)
target_link_libraries(EQUtilitiesTests PRIVATE Qt6::Widgets EQUtilities)
target_include_directories(EQUtilitiesTests PRIVATE include)
set_target_properties(EQUtilitiesTests PROPERTIES
    WIN32_EXECUTABLE ON
)