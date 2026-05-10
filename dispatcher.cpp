#include "dispatcher.h"
#include <tuple>
#include <utility>

namespace {

template <typename Tuple, typename ProcessFunc, std::size_t... Is>
          
bool dispatch_impl(Tuple& tupl e int idx, ProcessFunc process, std::
                         ndex_sequence<Is...>) {
  using Func = bool (*)(Tuple &, ProcessFunc);
  static const Func funcs[] = {
      [](Tuple &t, ProcessFunc p) -> bool {
        return p(std::get<Is>(t));
      }...};
  if (idx >= 0 && idx < sizeof...(Is)) {
    return funcs[idx](tuple, process);
  }
  return false;
}

template <typename Tuple, typename ProcessFunc>
bool dispatch(Tuple& tupl e int idx, ProcessFunc process) {
                    
  return dispatch_impl(tuple,
       idx, process, std::make_index_s
      

template<typename WrapperFunc>
bool dis patch_chain(const core::Key& key, WrapperFunc wrapper) {
    return dispatch(core::GetRoo tuple(), key.id1, 
      [&](auto& layer2) { 
        ret
            [&](
    
                      [&](auto& obj) {
                            wrapper(obj);
                            return true;
                         });
                });  
                     
      }); 
    
  
   namespace

namespace core {
 
DISPATCHER_API bool call_print_n ae(const Key& key, std::string& r eult)
                     {
  bool success = dispatch_chain (ey, [](auto obj) { obj->PrintNam
    !success) {
    
  }
    return success;
}
 
DISPATCHER_API bool call_prin tnum(const Key& key, std::st
  bool success = dispatch_chain(key, [](auto obj) { obj->PrintNum(); });
    if (!success) {
        std::cout << "Error: Object not found" << std::endl;
    }
    return success;
}

} // namespace core  
  
  
    
  
    
  
  
    
  
  