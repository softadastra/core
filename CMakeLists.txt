cmake_minimum_required(VERSION 3.20)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    project(softadastra_core
        VERSION 0.1.0
        DESCRIPTION "Softadastra Core - Foundational primitives"
        LANGUAGES CXX
    )
endif()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# ========================
# Standalone fallback options
# ========================
if(NOT DEFINED SOFTADASTRA_WARNINGS_AS_ERRORS)
    option(SOFTADASTRA_WARNINGS_AS_ERRORS "Treat warnings as errors" OFF)
endif()

if(SOFTADASTRA_UMBRELLA_BUILD)
    set(SOFTADASTRA_CORE_BUILD_TESTS ${SOFTADASTRA_BUILD_TESTS})
else()
    option(SOFTADASTRA_CORE_BUILD_TESTS "Build core tests" OFF)
endif()

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
# Compiler warnings
# ========================
if(MSVC)
    target_compile_options(softadastra_core PRIVATE /W4 /permissive-)
    if(SOFTADASTRA_WARNINGS_AS_ERRORS)
        target_compile_options(softadastra_core PRIVATE /WX)
    endif()
else()
    target_compile_options(softadastra_core PRIVATE -Wall -Wextra -Wpedantic)
    if(SOFTADASTRA_WARNINGS_AS_ERRORS)
        target_compile_options(softadastra_core PRIVATE -Werror)
    endif()
endif()

# ========================
# Target properties
# ========================
set_target_properties(softadastra_core PROPERTIES
    OUTPUT_NAME softadastra_core
    VERSION 0.1.0
    SOVERSION 0
    EXPORT_NAME core
)

# ========================
# Install
# ========================
install(
    TARGETS softadastra_core
    EXPORT softadastraCoreTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT softadastraCoreTargets
    FILE softadastraCoreTargets.cmake
    NAMESPACE softadastra::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/softadastra_core"
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/softadastra_coreConfigVersion.cmake"
    VERSION 0.1.0
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/softadastra_coreConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/softadastra_coreConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/softadastra_core"
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/softadastra_coreConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/softadastra_coreConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/softadastra_core"
)

# ========================
# Tests
# ========================
if(SOFTADASTRA_CORE_BUILD_TESTS)
    include(CTest)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/CMakeLists.txt")
        add_subdirectory(tests)
    else()
        message(STATUS "[core] tests/ missing CMakeLists.txt -> skipping")
    endif()
endif()

# ========================
# Summary
# ========================
message(STATUS "------------------------------------------------------")
message(STATUS "softadastra::core configured (0.1.0)")
message(STATUS "Include dir:     ${CMAKE_CURRENT_SOURCE_DIR}/include")
message(STATUS "Build tests:     ${SOFTADASTRA_CORE_BUILD_TESTS}")
message(STATUS "Warnings=error:  ${SOFTADASTRA_WARNINGS_AS_ERRORS}")
message(STATUS "Build type:      ${CMAKE_BUILD_TYPE}")
message(STATUS "Install prefix:  ${CMAKE_INSTALL_PREFIX}")
message(STATUS "------------------------------------------------------")
