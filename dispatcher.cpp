#include "dispatcher.h"
#include <tuple>
#include <utility>

namespace {

template<typename Layer3Tuple, typename WrapperFunc, std::size_t... Is>
bool dispatch_layer3_impl(Layer3Tuple& layer3, int idx, WrapperFunc wrapper, std::index_sequence<Is...>) {
    using Func = bool(*)(Layer3Tuple&, WrapperFunc);
    static const Func funcs[] = {
        [](Layer3Tuple& t, WrapperFunc w) -> bool {
            w(std::get<Is>(t));
            return true;
        }...
    };
    if (idx >= 0 && idx < sizeof...(Is)) {
        return funcs[idx](layer3, wrapper);
    }
    return false;
}

template<typename Layer3Tuple, typename WrapperFunc>
bool dispatch_layer3(Layer3Tuple& layer3, int idx, WrapperFunc wrapper) {
    return dispatch_layer3_impl(layer3, idx, wrapper, std::make_index_sequence<std::tuple_size_v<Layer3Tuple>>{});
}

template<typename Layer2Tuple, typename WrapperFunc, std::size_t... Is>
bool dispatch_layer2_impl(Layer2Tuple& layer2, int idx, const core::Key& key, WrapperFunc wrapper, std::index_sequence<Is...>) {
    using Func = bool(*)(Layer2Tuple&, const core::Key&, WrapperFunc);
    static const Func funcs[] = {
        [](Layer2Tuple& t, const core::Key& k, WrapperFunc w) -> bool {
            return dispatch_layer3(std::get<Is>(t), k.id3, w);
        }...
    };
    if (idx >= 0 && idx < sizeof...(Is)) {
        return funcs[idx](layer2, key, wrapper);
    }
    return false;
}

template<typename Layer2Tuple, typename WrapperFunc>
bool dispatch_layer2(Layer2Tuple& layer2, int idx, const core::Key& key, WrapperFunc wrapper) {
    return dispatch_layer2_impl(layer2, idx, key, wrapper, std::make_index_sequence<std::tuple_size_v<Layer2Tuple>>{});
}

template<typename Layer1Tuple, typename WrapperFunc, std::size_t... Is>
bool dispatch_layer1_impl(Layer1Tuple& layer1, int idx, const core::Key& key, WrapperFunc wrapper, std::index_sequence<Is...>) {
    using Func = bool(*)(Layer1Tuple&, const core::Key&, WrapperFunc);
    static const Func funcs[] = {
        [](Layer1Tuple& t, const core::Key& k, WrapperFunc w) -> bool {
            return dispatch_layer2(std::get<Is>(t), k.id2, k, w);
        }...
    };
    if (idx >= 0 && idx < sizeof...(Is)) {
        return funcs[idx](layer1, key, wrapper);
    }
    return false;
}

template<typename WrapperFunc>
bool dispatch(const core::Key& key, WrapperFunc wrapper) {
    return dispatch_layer1_impl(core::GetRootTuple(), key.id1, key, wrapper, 
        std::make_index_sequence<std::tuple_size_v<core::RootTuple>>{});
}

} // namespace

namespace core {

DISPATCHER_API bool call_print_name(const Key& key, std::string& result) {
    bool success = dispatch(key, [](auto obj) { obj->PrintName(); });
    if (!success) {
        std::cout << "Error: Object not found" << std::endl;
    }
    return success;
}

DISPATCHER_API bool call_print_num(const Key& key, std::string& result) {
    bool success = dispatch(key, [](auto obj) { obj->PrintNum(); });
    if (!success) {
        std::cout << "Error: Object not found" << std::endl;
    }
    return success;
}

} // namespace core