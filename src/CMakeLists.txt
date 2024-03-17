add_executable(prototype_cpp_modules)

set_target_properties(prototype_cpp_modules PROPERTIES CXX_STANDARD 20)
set_target_properties(prototype_cpp_modules PROPERTIES CXX_STANDARD_REQUIRED TRUE)

target_sources(prototype_cpp_modules
PUBLIC FILE_SET CXX_MODULES FILES
    "add.cpp"

PRIVATE
    "prototype_cpp_modules.cpp"
)

target_include_directories(prototype_cpp_modules
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include
    PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries(prototype_cpp_modules PRIVATE
    module_lib
)
