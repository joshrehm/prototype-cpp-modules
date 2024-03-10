#pragma once

#define MODULE_LIB_VERSION_MAJOR    0
#define MODULE_LIB_VERSION_MINOR    0
#define MODULE_LIB_VERSION_PATCH    1
#define MODULE_LIB_VERSION_BUILD    24070
#define MODULE_LIB_VERSION_COMMA    0,0,1

#define MODULE_LIB_VERSION          "0.0.1.24070"

struct module_lib_version_info
{
    char const* version_str;
    int major;
    int minor;
    int patch;
    int build;
};

extern "C" void module_lib_version(module_lib_version_info* verinfo);
