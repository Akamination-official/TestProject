#include "dispatcher.h"
#include <tuple>
#include <string>
#include <utility>

Class1 *c1_1 = new Class1();
Class1 *c1_2 = new Class1();

Class2 *c2_1 = new Class2();
Class2 *c2_2 = new Class2();

Class3 *c3_1 = new Class3();
Class3 *c3_2 = new Class3();
Class3 *c3_3 = new Class3();

Class4 *c4_1 = new Class4();
Class4 *c4_2 = new Class4();

Class5 *c5_1 = new Class5();
Class5 *c5_2 = new Class5();
Class5 *c5_3 = new Class5();

Class6 *c6_1 = new Class6();
Class6 *c6_2 = new Class6();
Class6 *c6_3 = new Class6();

Class7 *c7_1 = new Class7();
Class7 *c7_2 = new Class7();
Class7 *c7_3 = new Class7();

Class8 *c8_1 = new Class8();
Class8 *c8_2 = new Class8();
Class8 *c8_3 = new Class8();

Class9 *c9_1 = new Class9();
Class9 *c9_2 = new Class9();
Class9 *c9_3 = new Class9();

Class10 *c10_1 = new Class10();
Class10 *c10_2 = new Class10();
Class10 *c10_3 = new Class10();

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

template<typename Layer3Tuple, typename WrapperFunc, std::size_t... Is>
bool dispatch_layer3_impl(Layer3Tuple& layer3, int id3, WrapperFunc wrapper, std::index_sequence<Is...>) {
    using Func = bool(*)(Layer3Tuple&, WrapperFunc);
    static const Func funcs[] = {
        [](Layer3Tuple& t, WrapperFunc w) -> bool {
            w(std::get<Is>(t));
            return true;
        }...
    };
    if (id3 >= 0 && id3 < sizeof...(Is)) {
        return funcs[id3](layer3, wrapper);
    }
    return false;
}

template<typename Layer3Tuple, typename WrapperFunc>
bool dispatch_layer3(Layer3Tuple& layer3, int id3, WrapperFunc wrapper) {
    return dispatch_layer3_impl(layer3, id3, wrapper, std::make_index_sequence<std::tuple_size_v<Layer3Tuple>>{});
}

template<typename Layer2Tuple, typename WrapperFunc, std::size_t... Is>
bool dispatch_layer2_impl(Layer2Tuple& layer2, int id2, int id3, WrapperFunc wrapper, std::index_sequence<Is...>) {
    using Func = bool(*)(Layer2Tuple&, int, int, WrapperFunc);
    static const Func funcs[] = {
        [](Layer2Tuple& t, int id2, int id3, WrapperFunc w) -> bool {
            return dispatch_layer3(std::get<Is>(t), id3, w);
        }...
    };
    if (id2 >= 0 && id2 < sizeof...(Is)) {
        return funcs[id2](layer2, id2, id3, wrapper);
    }
    return false;
}

template<typename Layer2Tuple, typename WrapperFunc>
bool dispatch_layer2(Layer2Tuple& layer2, int id2, int id3, WrapperFunc wrapper) {
    return dispatch_layer2_impl(layer2, id2, id3, wrapper, std::make_index_sequence<std::tuple_size_v<Layer2Tuple>>{});
}

template<typename Layer1Tuple, typename WrapperFunc, std::size_t... Is>
bool dispatch_layer1_impl(Layer1Tuple& layer1, int id1, int id2, int id3, WrapperFunc wrapper, std::index_sequence<Is...>) {
    using Func = bool(*)(Layer1Tuple&, int, int, int, WrapperFunc);
    static const Func funcs[] = {
        [](Layer1Tuple& t, int id1, int id2, int id3, WrapperFunc w) -> bool {
            return dispatch_layer2(std::get<Is>(t), id2, id3, w);
        }...
    };
    if (id1 >= 0 && id1 < sizeof...(Is)) {
        return funcs[id1](layer1, id1, id2, id3, wrapper);
    }
    return false;
}

template<typename WrapperFunc>
bool dispatch(int id1, int id2, int id3, WrapperFunc wrapper) {
    return dispatch_layer1_impl(rootTuple, id1, id2, id3, wrapper, std::make_index_sequence<std::tuple_size_v<decltype(rootTuple)>>{});
}

}

namespace core {

DISPATCHER_API RootTuple& GetRootTuple() {
    return rootTuple;
}

extern "C" DISPATCHER_API bool call_print_name(int id1, int id2, int id3, std::string &result) {
    bool success = dispatch(id1, id2, id3, [](auto obj) { obj->PrintName(); });
    if (!success) {
        std::cout << "Error: Object not found" << std::endl;
    }
    return success;
}

extern "C" DISPATCHER_API bool call_print_num(int id1, int id2, int id3, std::string &result) {
    bool success = dispatch(id1, id2, id3, [](auto obj) { obj->PrintNum(); });
    if (!success) {
        std::cout << "Error: Object not found" << std::endl;
    }
    return success;
}

} // namespace core