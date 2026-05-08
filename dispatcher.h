#pragma once

#ifdef DISPATCHER_EXPORTS
#    define DISPATCHER_API __declspec(dllexport)
#else
#    define DISPATCHER_API __declspec(dllimport)
#endif

#include <tuple>
#include <string>
#include "classes.h"

namespace core {

using Layer3Class1 = std::tuple<Class1*, Class1*>;
using Layer3Class2 = std::tuple<Class2*, Class2*>;
using Layer3Class3 = std::tuple<Class3*, Class3*, Class3*>;
using Layer3Class4 = std::tuple<Class4*, Class4*>;
using Layer3Class5 = std::tuple<Class5*, Class5*, Class5*>;
using Layer3Class6 = std::tuple<Class6*, Class6*, Class6*>;
using Layer3Class7 = std::tuple<Class7*, Class7*, Class7*>;
using Layer3Class8 = std::tuple<Class8*, Class8*, Class8*>;
using Layer3Class9 = std::tuple<Class9*, Class9*, Class9*>;
using Layer3Class10 = std::tuple<Class10*, Class10*, Class10*>;

using Layer2Group0 = std::tuple<Layer3Class1, Layer3Class2>;
using Layer2Group1 = std::tuple<Layer3Class3, Layer3Class4>;
using Layer2Group2 = std::tuple<Layer3Class5, Layer3Class6>;
using Layer2Group3 = std::tuple<Layer3Class7, Layer3Class8>;
using Layer2Group4 = std::tuple<Layer3Class9, Layer3Class10>;

using RootTuple = std::tuple<Layer2Group0, Layer2Group1, Layer2Group2, Layer2Group3, Layer2Group4>;

DISPATCHER_API RootTuple& GetRootTuple();

extern "C" DISPATCHER_API bool call_print_name(int id1, int id2, int id3, std::string& result);
extern "C" DISPATCHER_API bool call_print_num(int id1, int id2, int id3, std::string& result);

} // namespace core