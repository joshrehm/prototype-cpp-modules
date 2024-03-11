module;

export module mlib;

namespace mlib {

export struct module_lib_version_info
{
    char const* version_str;
    int major;
    int minor;
    int patch;
    int build;
};

export void module_lib_version(module_lib_version_info* verinfo);

}
