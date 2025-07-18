qt_add_executable(EQUtilitiesTests
    EQTests.hpp
    EQTests.cpp
    main.cpp
)

target_link_libraries(EQUtilitiesTests PRIVATE Qt6::Widgets EQUtilities)
target_include_directories(EQUtilitiesTests PRIVATE include)

if (WIN32)
    set_target_properties(EQUtilitiesTests PROPERTIES WIN32_EXECUTABLE ON)
endif()