cmake_minimum_required(VERSION 3.20)

project(softadastra_core
    VERSION 0.1.0
    DESCRIPTION "Softadastra Core - Foundational primitives"
    LANGUAGES CXX
)

include(GNUInstallDirs)

# ========================
# Options
# ========================
option(SOFTADASTRA_CORE_BUILD_TESTS "Build core tests" ON)

# ========================
# Global settings
# ========================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# ========================
# Sources
# ========================
file(GLOB_RECURSE SOFTADASTRA_CORE_SOURCES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# ========================
# Library
# ========================
add_library(softadastra_core ${SOFTADASTRA_CORE_SOURCES})
add_library(softadastra::core ALIAS softadastra_core)

target_compile_features(softadastra_core PUBLIC cxx_std_20)

target_include_directories(softadastra_core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# ========================
# Compiler options
# ========================
if(MSVC)
    target_compile_options(softadastra_core PRIVATE /W4 /permissive-)
else()
    target_compile_options(softadastra_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

# ========================
# Target properties
# ========================
set_target_properties(softadastra_core PROPERTIES
    OUTPUT_NAME softadastra_core
    VERSION ${PROJECT_VERSION}
    SOVERSION 0
    EXPORT_NAME core
)

# ========================
# Tests
# ========================
if(SOFTADASTRA_CORE_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# ========================
# Summary
# ========================
message(STATUS "------------------------------------------------------")
message(STATUS "softadastra::core configured (${PROJECT_VERSION})")
message(STATUS "Include dir:     ${CMAKE_CURRENT_SOURCE_DIR}/include")
message(STATUS "Build tests:     ${SOFTADASTRA_CORE_BUILD_TESTS}")
message(STATUS "Build type:      ${CMAKE_BUILD_TYPE}")
message(STATUS "------------------------------------------------------")
