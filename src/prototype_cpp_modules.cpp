#include"prototype_cpp_modules/prototype_cpp_modules.h"
#include<iostream>
#include<module_lib/module_lib.h>

import adder;
import mlib;

int main()
{
    mlib::module_lib_version_info mlibv;
    mlib::module_lib_version(&mlibv);

    std::cout << mlibv.version_str << std::endl;
    std::cout << "1 + 5 = " << add(1, 5) << std::endl;
    
    return 0;
}
