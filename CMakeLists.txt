cmake_minimum_required(VERSION 3.25)

#
# Configure CMake properties
list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

#
# Includes
include(PrototypeCppModulesOptions)

#
# Project setup
generate_version_header("${CMAKE_CURRENT_SOURCE_DIR}/VERSION"
                        "${CMAKE_CURRENT_SOURCE_DIR}/include/prototype_cpp_modules/prototype_cpp_modules_version.h"
                        FROM_TEMPLATE  "prototype_cpp_modules_version.h.in"
                        VARIABLE        PROTOTYPE_CPP_MODULES_VERSION)
project(prototype_cpp_modules VERSION ${PROTOTYPE_CPP_MODULES_VERSION} LANGUAGES C CXX )

#
# Source files
add_subdirectory(external)
add_subdirectory(src)

#
# Unit Testing
if (PROTOTYPE_CPP_MODULES_RUN_TESTS_ON_BUILD)
    set(PROTOTYPE_CPP_MODULES_ENABLE_TESTS ON)
endif()

message_bool(PROTOTYPE_CPP_MODULES_ENABLE_TESTS
    "-- ${PROJECT_NAME}: Testing is enabled"
    "-- ${PROJECT_NAME}: Testing is disabled")
message_bool(PROTOTYPE_CPP_MODULES_RUN_TESTS_ON_BUILD
    "-- ${PROJECT_NAME}: Tests will run on build"
    "-- ${PROJECT_NAME}: Tests will not run on build")

if (PROTOTYPE_CPP_MODULES_ENABLE_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif()
