cmake_minimum_required(VERSION 3.20)

project(telemetry_toolkit LANGUAGES CXX)

# Configure C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(telemetry_core
    src/temperature_conversion.cpp
    src/measures_statistics.cpp
)

target_include_directories(telemetry_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Enable compiler warnings and treat them as errors
target_compile_options(telemetry_core
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
)

add_executable(telemetry_toolkit
    src/main.cpp
)

target_link_libraries(telemetry_toolkit
    PRIVATE
        telemetry_core
)

# Enable testing with CTest
enable_testing()

add_executable(test_temperature_conversion
    tests/test_temperature_conversion.cpp
)

target_link_libraries(test_temperature_conversion
    PRIVATE
        telemetry_core
)

# Add a test for the temperature conversion functions
add_test(
    NAME temperature_conversion_tests
    COMMAND test_temperature_conversion
)


add_executable(test_measures_statistics
    tests/test_measures_statistics.cpp
)

target_link_libraries(test_measures_statistics
    PRIVATE
        telemetry_core
)

# Add a test for the measures statistics functions
add_test(
    NAME measures_statistics_tests
    COMMAND test_measures_statistics
)