cmake_minimum_required(VERSION 3.20)

# Project Definition
project(
    pga_icp_engine
    VERSION 1.0.0
    DESCRIPTION "High-Performance PGA-Based Real-Time Point Cloud Registration Engine"
    LANGUAGES CXX
)

# Enforce C++20 Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default to Release build type if none specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo" "MinSizeRel")
endif()

# Find OpenMP Package
find_package(OpenMP REQUIRED)

# Source and Header File Definitions
file(GLOB_RECURSE ENGINE_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE ENGINE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Define Core Static Library
add_library(pga_icp_core STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})

# Public Include Directory Configuration
target_include_directories(pga_icp_core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Compiler-Specific Optimization, AVX2, and Warning Flags
if(MSVC)
    target_compile_options(pga_icp_core PRIVATE
        /W4
        /O2
        /arch:AVX2
        /utf-8
    )
else()
    # GCC / Clang Flags
    target_compile_options(pga_icp_core PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -O3
        -mavx2
        -mfma
        -fPIC
    )
endif()

# Link OpenMP
target_link_libraries(pga_icp_core PUBLIC OpenMP::OpenMP_CXX)

# Define Main Binary Executable
add_executable(pga_icp_demo src/main.cpp)
target_link_libraries(pga_icp_demo PRIVATE pga_icp_core)

# Enable LTO (Link Time Optimization) for Release Builds
include(CheckIPOSupported)
check_ipo_supported(RESULT ipo_supported OUTPUT ipo_output)
if(ipo_supported AND CMAKE_BUILD_TYPE STREQUAL "Release")
    set_property(TARGET pga_icp_core PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    set_property(TARGET pga_icp_demo PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

# Set Target Output Directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
