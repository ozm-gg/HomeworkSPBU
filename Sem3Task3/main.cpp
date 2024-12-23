#include <iostream>
#include "Func.h"

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    auto result = OneToTwo(std::move(vec), 2);
    for(const auto& row: result){
        for(const auto& el: row){
            std::cout<<el<<"\t";
        }
        std::cout<<std::endl;
    }
    return 0;
}
