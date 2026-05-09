#include "dispatcher.h"
#include <iostream>
#include <string>

int main() {
    std::string result;

    std::cout << "=== Testing PrintName (Key struct) ===" << std::endl;

    std::cout << "\nTest 1: Key{0, 0, 0} -> Class1::c1_1" << std::endl;
    core::Key key1 = {0, 0, 0};
    bool success1 = core::call_print_name(key1, result);
    std::cout << "  (Success: " << (success1 ? "Yes" : "No") << ")" << std::endl;

    std::cout << "\nTest 2: Key{1, 1, 1} -> Class4::c4_2" << std::endl;
    core::Key key2 = {1, 1, 1};
    bool success2 = core::call_print_name(key2, result);
    std::cout << "  (Success: " << (success2 ? "Yes" : "No") << ")" << std::endl;

    std::cout << "\nTest 3: Key{4, 1, 2} -> Class10::c10_3" << std::endl;
    core::Key key3 = {4, 1, 2};
    bool success3 = core::call_print_name(key3, result);
    std::cout << "  (Success: " << (success3 ? "Yes" : "No") << ")" << std::endl;

    std::cout << "\n=== Testing PrintNum (Key struct) ===" << std::endl;

    std::cout << "\nTest 4: Key{0, 0, 0} -> Class1::c1_1" << std::endl;
    bool success4 = core::call_print_num(key1, result);
    std::cout << "  (Success: " << (success4 ? "Yes" : "No") << ")" << std::endl;

    std::cout << "\nTest 5: Key{1, 1, 1} -> Class4::c4_2" << std::endl;
    bool success5 = core::call_print_num(key2, result);
    std::cout << "  (Success: " << (success5 ? "Yes" : "No") << ")" << std::endl;

    std::cout << "\nTest 6: Key{4, 1, 2} -> Class10::c10_3" << std::endl;
    bool success6 = core::call_print_num(key3, result);
    std::cout << "  (Success: " << (success6 ? "Yes" : "No") << ")" << std::endl;

    return 0;
}