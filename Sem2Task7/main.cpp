#include <iostream>
#include "BinTree.h"




int main() {
    setlocale(LC_ALL, "Russian");
    Lessons::BinTree tree;
    //int values[10] = {3, 2, 4};
    int values[10] = {5, 2, 1, 4,6, 12,7,11,3,10};
    //int values[10] = {1,3,5,7,9,11,13,15,17,19};
    for (int i = 0; i < 10; ++i) {
        tree.Add(values[i]);
    }

    int input;
    int inputValue;
    std::cout<<"1 - Добавить элемент\n"
               "2 - удалить элемент\n";
    bool isReading = true;
    while (isReading) {
        std::cin >> input;
        switch (input) {
            case 0:
                isReading = false;
                break;
            case 1:
                std::cin>>inputValue;
                tree.Add(inputValue);
                break;

            case 2:
                std::cin>>inputValue;
                tree.Pop(inputValue);
                break;

        }
        tree.show();
        std::cout<<tree.FindEvenWithZeroWeight()<<std::endl;
    }
    return 0;
}
