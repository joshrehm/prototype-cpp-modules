# Prototype C++ Modules with CMake Repository

A prototype project I am using to figure out C++ modules. It doesn't do anything
useful.

# Configure and Build

## Requirements

 - Conan 2.0+
 - CMake 3.28+

## Configure Step

This project integrates Conan 2 into the build process. Conan is automatically
invoked during the cmake configuration process.

To configure the project with tests:

```
cmake --preset=<preset_name> -DMODULE_LIB_RUN_TESTS_ON_BUILD=ON
```

The `<preset_name>` placeholder should be an available preset defined in
CMakePresets.json:

- windows-x86-debug
- windows-x86-release
- windows-x64-debug
- windows-x64-release
- linux-x86-debug
- linux-x86-release
- linux-x64-debug
- linux-x64-release

If you do not want to run tests automatically, use `-DMODULE_LIB_ENABLE_TESTS=ON` 
instead of `-DMODULE_LIB_RUN_TESTS_ON_BUILD=ON`. Omit both parameters
to disable testing.

Available CMake Cache Variables:

 - `WARNINGS_AS_ERRORS`: Treats compiler warnings as errors. `ON` by default. This 
   variable is "global" in that it affects the default value of all subprojets that
   utilize this template.
 - `PROJECT_OUTPUT_PATH`: Specifies the output path of built binaries. The default is 
   the project's `.bin` directory. This variable is "global" in that it affects the 
   default value of all subprojects that utilize this template.
 - `MODULE_LIB_OUTPUT_PATH`: Specifies the output path of this project's 
   built binaries. Unlike `PROJECT_OUTPUT_PATH`, this variable affects only this
   project. Defaults to `${PROJECT_OUTPUT_PATH}`.
 - `MODULE_LIB_ENABLE_TESTS`: Enable unit tests. `OFF` by default.
 - `MODULE_LIB_RUN_TESTS_ON_BUILD`: Run tests automatically after build.
   Implies `MODULE_LIB_ENABLE_TESTS`. `OFF` by default.
 - `MODULE_LIB_ENABLE_CPPCHECK`: Enables cppcheck static analysis. `ON`
   by default.
 - `MODULE_LIB_WARNINGS_AS_ERRORS`: Treats compiler warnings as errors.
   Set to `${WARNINGS_AS_ERRORS}` by default.


## Build Step

To build the project:

```
cmake --build --preset=<preset_name>
```

Alternatively you may open the project in Visual Studio or Visual Studio Code and 
build from the menu after selecting your desire configuration. Other IDEs may 
work, but they have not been tested.

By default, output binaries will be put into the project's `.bin` directory.
