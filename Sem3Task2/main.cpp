#include <iostream>
#include "Func.h"

int main() {
    int value;
    std::vector<int> vec;
    while (std::cin >> value) {
        if (value == 0) break;
        vec.push_back(value);
    }
    std::cout << "enter find value" << std::endl;
    std::cin >> value;
    std::cout << (BinSearch(vec, value) ? "The value is in vec" : "The value isn't in vec") << std::endl;
    return 0;
}
