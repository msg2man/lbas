cmake_minimum_required(VERSION 3.10)

# Set the project name
project(LBASimulatorProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(LBASimulator main.cpp Logger.cpp LBASimulator.cpp
               LBAConfig.cpp LBTwoChoice.cpp LBTwoChoiceRR.cpp
               LBTwoChoiceBias.cpp LBAFactory.cpp LBAResults.cpp
               LBAlgorithm.cpp)

# Set the output directory for the binary
set_target_properties(LBASimulator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
)

# Add configurations for Debug and Release builds
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/target/debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/target/release)

# Add flags for debug and release builds
target_compile_options(LBASimulator PRIVATE
    $<$<CONFIG:DEBUG>:-g>
    $<$<CONFIG:RELEASE>:-O3>
)

# Optionally, you can set specific definitions for each build type
target_compile_definitions(LBASimulator PRIVATE
    $<$<CONFIG:DEBUG>:DEBUG_BUILD>
    $<$<CONFIG:RELEASE>:NDEBUG>
)
