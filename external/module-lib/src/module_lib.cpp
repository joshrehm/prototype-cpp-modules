#include"module_lib/module_lib.h"

extern "C" void module_lib_version(module_lib_version_info* verinfo)
{
    *verinfo = module_lib_version_info 
        {
            .version_str = MODULE_LIB_VERSION,
            .major = MODULE_LIB_VERSION_MAJOR,
            .minor = MODULE_LIB_VERSION_MINOR,
            .patch = MODULE_LIB_VERSION_PATCH,
            .build = MODULE_LIB_VERSION_BUILD
        };
}
