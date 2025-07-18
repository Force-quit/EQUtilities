cmake_minimum_required(VERSION 3.26)
project(EQUtilities LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

include(FetchContent)
FetchContent_Declare(
    EUtilities
    GIT_REPOSITORY https://github.com/Force-quit/EUtilities.git
    GIT_TAG        main
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

if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory(tests)
endif()