
#ifdef USE_MODULES
import std;
#else
#include <iostream>
#endif

namespace mylib {

inline void f() { std::cout << "f()\n"; }

void g();

}