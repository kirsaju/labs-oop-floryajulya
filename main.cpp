#include <iostream>
#include "lib.h"

int main() {
    std::string str;
    std::cin >> str;
    try {
        std::cout << checkBracesValidity(str) << std::endl;
    }
    catch(std::invalid_argument ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}