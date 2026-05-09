#pragma once

#include <iostream>
#include <tuple>

class Class1 {
public:
    void PrintName() { std::cout << "Class1" << std::endl; }
    void PrintNum() { std::cout << 1 << std::endl; }
};

class Class2 {
public:
    void PrintName() { std::cout << "Class2" << std::endl; }
    void PrintNum() { std::cout << 2 << std::endl; }
};

class Class3 {
public:
    void PrintName() { std::cout << "Class3" << std::endl; }
    void PrintNum() { std::cout << 3 << std::endl; }
};

class Class4 {
public:
    void PrintName() { std::cout << "Class4" << std::endl; }
    void PrintNum() { std::cout << 4 << std::endl; }
};

class Class5 {
public:
    void PrintName() { std::cout << "Class5" << std::endl; }
    void PrintNum() { std::cout << 5 << std::endl; }
};

class Class6 {
public:
    void PrintName() { std::cout << "Class6" << std::endl; }
    void PrintNum() { std::cout << 6 << std::endl; }
};

class Class7 {
public:
    void PrintName() { std::cout << "Class7" << std::endl; }
    void PrintNum() { std::cout << 7 << std::endl; }
};

class Class8 {
public:
    void PrintName() { std::cout << "Class8" << std::endl; }
    void PrintNum() { std::cout << 8 << std::endl; }
};

class Class9 {
public:
    void PrintName() { std::cout << "Class9" << std::endl; }
    void PrintNum() { std::cout << 9 << std::endl; }
};

class Class10 {
public:
    void PrintName() { std::cout << "Class10" << std::endl; }
    void PrintNum() { std::cout << 10 << std::endl; }
};

extern Class1* c1_1;
extern Class1* c1_2;

extern Class2* c2_1;
extern Class2* c2_2;

extern Class3* c3_1;
extern Class3* c3_2;
extern Class3* c3_3;

extern Class4* c4_1;
extern Class4* c4_2;

extern Class5* c5_1;
extern Class5* c5_2;
extern Class5* c5_3;

extern Class6* c6_1;
extern Class6* c6_2;
extern Class6* c6_3;

extern Class7* c7_1;
extern Class7* c7_2;
extern Class7* c7_3;

extern Class8* c8_1;
extern Class8* c8_2;
extern Class8* c8_3;

extern Class9* c9_1;
extern Class9* c9_2;
extern Class9* c9_3;

extern Class10* c10_1;
extern Class10* c10_2;
extern Class10* c10_3;

namespace core {

struct Key {
    int id1;
    int id2;
    int id3;
};

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

#ifdef CLASS_EXPORTS
#    define CLASS_API __declspec(dllexport)
#else
#    define CLASS_API __declspec(dllimport)
#endif

CLASS_API RootTuple& GetRootTuple();

} // namespace core