module;

#include "boost/charconv/config.hpp"
#include "boost/charconv/detail/config.hpp"
#include <limits.h>

export module charconv;

import std;

extern "C++" {

#include "boost/charconv/to_chars.hpp"

}
