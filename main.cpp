#include "dispatcher.h"
#include <iostream>
#include <string>

int main() {
    std::string result;

    std::cout << "=== Testing PrintName ===" << std::endl;

    std::cout << "\nTest 1: id1=0, id2=0, id3=0 -> Class1::c1_1" << std::endl;
    bool success1 = core::call_print_name(0, 0, 0, result);
    std::cout << "  (Success: " << (success1 ? "Yes" : "No") << ")" << std::endl;

    std::cout << "\nTest 2: id1=1, id2=1, id3=1 -> Class4::c4_2" << std::endl;
    bool success2 = core::call_print_name(1, 1, 1, result);
    std::cout << "  (Success: " << (success2 ? "Yes" : "No") << ")" << std::endl;

    std::cout << "\nTest 3: id1=4, id2=1, id3=2 -> Class10::c10_3" << std::endl;
    bool success3 = core::call_print_name(4, 1, 2, result);
    std::cout << "  (Success: " << (success3 ? "Yes" : "No") << ")" << std::endl;

    std::cout << "\n=== Testing PrintNum ===" << std::endl;

    std::cout << "\nTest 4: id1=0, id2=0, id3=0 -> Class1::c1_1" << std::endl;
    bool success4 = core::call_print_num(0, 0, 0, result);
    std::cout << "  (Success: " << (success4 ? "Yes" : "No") << ")" << std::endl;

    std::cout << "\nTest 5: id1=1, id2=1, id3=1 -> Class4::c4_2" << std::endl;
    bool success5 = core::call_print_num(1, 1, 1, result);
    std::cout << "  (Success: " << (success5 ? "Yes" : "No") << ")" << std::endl;

    std::cout << "\nTest 6: id1=4, id2=1, id3=2 -> Class10::c10_3" << std::endl;
    bool success6 = core::call_print_num(4, 1, 2, result);
    std::cout << "  (Success: " << (success6 ? "Yes" : "No") << ")" << std::endl;

    return 0;
}