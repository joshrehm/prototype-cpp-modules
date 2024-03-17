add_library(module_lib)

set_target_properties(module_lib PROPERTIES CXX_STANDARD 20)
set_target_properties(module_lib PROPERTIES CXX_STANDARD_REQUIRED TRUE)

target_sources(module_lib PRIVATE 
    "module_lib.cpp"
)

# Set target includes
target_include_directories(module_lib
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/../include)
