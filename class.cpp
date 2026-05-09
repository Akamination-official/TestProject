#include "class.h"
#include <tuple>

Class1* c1_1 = new Class1();
Class1* c1_2 = new Class1();

Class2* c2_1 = new Class2();
Class2* c2_2 = new Class2();

Class3* c3_1 = new Class3();
Class3* c3_2 = new Class3();
Class3* c3_3 = new Class3();

Class4* c4_1 = new Class4();
Class4* c4_2 = new Class4();

Class5* c5_1 = new Class5();
Class5* c5_2 = new Class5();
Class5* c5_3 = new Class5();

Class6* c6_1 = new Class6();
Class6* c6_2 = new Class6();
Class6* c6_3 = new Class6();

Class7* c7_1 = new Class7();
Class7* c7_2 = new Class7();
Class7* c7_3 = new Class7();

Class8* c8_1 = new Class8();
Class8* c8_2 = new Class8();
Class8* c8_3 = new Class8();

Class9* c9_1 = new Class9();
Class9* c9_2 = new Class9();
Class9* c9_3 = new Class9();

Class10* c10_1 = new Class10();
Class10* c10_2 = new Class10();
Class10* c10_3 = new Class10();

namespace {

core::RootTuple rootTuple = std::make_tuple(
    std::make_tuple(
        std::make_tuple(c1_1, c1_2),
        std::make_tuple(c2_1, c2_2)
    ),
    std::make_tuple(
        std::make_tuple(c3_1, c3_2, c3_3),
        std::make_tuple(c4_1, c4_2)
    ),
    std::make_tuple(
        std::make_tuple(c5_1, c5_2, c5_3),
        std::make_tuple(c6_1, c6_2, c6_3)
    ),
    std::make_tuple(
        std::make_tuple(c7_1, c7_2, c7_3),
        std::make_tuple(c8_1, c8_2, c8_3)
    ),
    std::make_tuple(
        std::make_tuple(c9_1, c9_2, c9_3),
        std::make_tuple(c10_1, c10_2, c10_3)
    )
);

} // namespace

namespace core {

CLASS_API RootTuple& GetRootTuple() {
    return rootTuple;
}

} // namespace core