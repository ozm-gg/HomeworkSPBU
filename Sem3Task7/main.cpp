#include <iostream>
#include "Func.h"

int main() {
    std::vector<std::string> input = {
            "1 - 11, 21, 41",
            "2 - 21, 23, 24",
            "3 - 23",
            "4 - 41, 24, 44",
    };

    auto result = VasyasDictionary(4, input);
    for (auto& p : result){
        std::cout<<p.first;
        for (auto& s : p.second){
            std::cout<<"\t"<<s;
        }
        std::cout<<std::endl;
    }
    return 0;
}
