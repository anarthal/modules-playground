module;

#define USE_MODULES
#include "mylib_iface.hpp"

export module mylib;

export namespace mylib {
using mylib::f;
using mylib::g;
}