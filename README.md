# Prototype C++ Modules with CMake Repository

A prototype project I am using to figure out C++ modules. It doesn't do anything
useful.

# Configure and Build

## Requirements

 - CMake 3.28+

## Configure Step

To configure the project:

```
mkdir build
cd build
cmake ..
```

## Build Step

To build the project:

```
cmake --build .
```

# Layout

The project consists of two projects: prototype-cpp-modules and module_lib. 

The CMake setup is pretty standard. A root "CMakeLists.txt" file which includes the "src"
directory. From there, the prototype_cpp_modules target and executable are defined. The
root "CMakeLists.txt" file also includes the "external" directory containing our static
module library.

The static module_lib library contains C++ 20 our C++ 20 module's source code. I placed it
in a static library just to ensure it could be included and linked correctly, but there's
no reason why module source can't be placed directly into the prototype-cpp-modules 
executable.

Modules are defined through module interface files, which may contain a module definition
(or declaration) and an optional implementation. The module_lib separates the two into an
definition and separate implementation. I chose to put module interface files in the 
"modules" directory to separate them from the implementation files, similar to how public
include files are handled. However, there is no reason the interface files need to be
separated from the implementation files other than for organizational purposes.

CMake is informed about the module interface files via the `FILE_SET CXX_MODULES` keywords 
when specifying target source code. You can find this call in the 
"external/module-lib/modules/CMakeLists.txt" file.


