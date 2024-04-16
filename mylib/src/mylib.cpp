
#include "mylib_iface.hpp"
#include <iostream>
#include <ratio>
#include <chrono>

void mylib::g()
{
    std::cout << "g(): " << std::chrono::system_clock::now().time_since_epoch().count() << std::endl;
}