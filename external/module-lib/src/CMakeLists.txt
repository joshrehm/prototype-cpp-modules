#
# Set up our executable
add_library(module_lib
    "module_lib.cpp"
 )

set_standard_target_options(module_lib)

#
# Enable CppCheck
if (MODULE_LIB_ENABLE_CPPCHECK)
    include(CppCheck)
    enable_cppcheck(module_lib)
endif()

# Set target includes
target_include_directories(module_lib
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/../include)

#
# Set target libraries
find_package(fmt REQUIRED)
target_link_libraries(module_lib PRIVATE
    fmt::fmt
)
