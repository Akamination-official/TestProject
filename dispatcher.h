#pragma once

#ifdef DISPATCHER_EXPORTS
#    define DISPATCHER_API __declspec(dllexport)
#else
#    define DISPATCHER_API __declspec(dllimport)
#endif

#include <string>
#include "class.h"

namespace core {

DISPATCHER_API bool call_print_name(const Key& key, std::string& result);
DISPATCHER_API bool call_print_num(const Key& key, std::string& result);

} // namespace core