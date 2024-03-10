#include"prototype_cpp_modules/prototype_cpp_modules.h"
#include<iostream>
#include<module_lib/module_lib.h>

int main()
{
    module_lib_version_info mlibv;
    module_lib_version(&mlibv);

    std::cout << mlibv.version_str << std::endl;
    return 0;
}
