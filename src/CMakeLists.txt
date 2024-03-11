#
# Set up our executable
add_executable(prototype_cpp_modules)

target_sources(prototype_cpp_modules
PUBLIC FILE_SET CXX_MODULES FILES
    "add.cpp"

PRIVATE
    "prototype_cpp_modules.cpp"
)

set_standard_target_options(prototype_cpp_modules)

#
# Enable CppCheck
if (PROTOTYPE_CPP_MODULES_ENABLE_CPPCHECK)
    include(CppCheck)
    enable_cppcheck(prototype_cpp_modules)
endif()

#
# Set output directory
set_target_properties(prototype_cpp_modules PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROTOTYPE_CPP_MODULES_OUTPUT_PATH})

# Set target includes
target_include_directories(prototype_cpp_modules
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/../include)

#
# Set target libraries
find_package(fmt REQUIRED)
target_link_libraries(prototype_cpp_modules PRIVATE
    fmt::fmt
    module_lib
)
