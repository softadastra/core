cmake_minimum_required(VERSION 3.20)

project(softadastra_core
    VERSION 0.1.0
    DESCRIPTION "Softadastra Core - Foundational primitives"
    LANGUAGES CXX
)

# ========================
# Options
# ========================
option(SOFTADASTRA_CORE_BUILD_TESTS "Build core tests" ON)

# ========================
# Library
# ========================
add_library(softadastra_core)

# C++ standard
target_compile_features(softadastra_core PUBLIC cxx_std_20)

# ========================
# Include directories
# ========================
target_include_directories(softadastra_core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# ========================
# Sources
# ========================
file(GLOB_RECURSE CORE_SOURCES
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

target_sources(softadastra_core
    PRIVATE
        ${CORE_SOURCES}
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
# Position Independent Code
# ========================
set_target_properties(softadastra_core PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

# ========================
# Namespacing
# ========================
add_library(softadastra::core ALIAS softadastra_core)

# ========================
# Tests
# ========================
if(SOFTADASTRA_CORE_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
