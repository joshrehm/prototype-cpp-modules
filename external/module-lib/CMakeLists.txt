cmake_minimum_required(VERSION 3.25)

#
# Configure CMake properties
list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

#
# Includes
include(ModuleLibOptions)

#
# Project setup
generate_version_header("${CMAKE_CURRENT_SOURCE_DIR}/VERSION"
                        "${CMAKE_CURRENT_SOURCE_DIR}/include/module_lib/module_lib_version.h"
                        FROM_TEMPLATE  "module_lib_version.h.in"
                        VARIABLE        MODULE_LIB_VERSION)
project(module_lib VERSION ${MODULE_LIB_VERSION} LANGUAGES C CXX )

#
# Source files
add_subdirectory(src)

#
# Unit Testing
if (MODULE_LIB_RUN_TESTS_ON_BUILD)
    set(MODULE_LIB_ENABLE_TESTS ON)
endif()

message_bool(MODULE_LIB_ENABLE_TESTS
    "-- ${PROJECT_NAME}: Testing is enabled"
    "-- ${PROJECT_NAME}: Testing is disabled")
message_bool(MODULE_LIB_RUN_TESTS_ON_BsUILD
    "-- ${PROJECT_NAME}: Tests will run on build"
    "-- ${PROJECT_NAME}: Tests will not run on build")

if (MODULE_LIB_ENABLE_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif()
