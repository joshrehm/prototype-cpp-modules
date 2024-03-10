#
# Add our test executable
add_executable(module_lib_tests
    "module_lib_tests.cpp"
)

set_standard_target_options(module_lib_tests)

#
# Enable CppCheck
if (MODULE_LIB_ENABLE_CPPCHECK)
    include(CppCheck)
    enable_cppcheck(module_lib_tests)
endif()

#
# Set output directory
set_target_properties(module_lib_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${MODULE_LIB_OUTPUT_PATH})

# Set target includes
target_include_directories(module_lib_tests
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/../include)

#
# Set target libraries
find_package(Catch2 REQUIRED)
find_package(fmt REQUIRED)

target_link_libraries(module_lib_tests PRIVATE
    Catch2::Catch2WithMain
    fmt::fmt
)

#
# Discover tests and automatically run on build
include(Catch)
catch_discover_tests(module_lib_tests)

if (MODULE_LIB_RUN_TESTS_ON_BUILD)
    add_custom_command(TARGET module_lib_tests POST_BUILD
                       COMMAND ctest --output-on-failure
                       WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
endif()
