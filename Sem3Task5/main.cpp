#include <iostream>
#include "CustomList.h"

int main() {
    CustomList<int> cl;

    cl.pushFront(1);
    cl.pushBack(2);
    cl.insertBefore(2, 3);
    cl.insertAfter(1, 4);

    std::cout << "Current List: ";
    cl.print();

    cl.pop();
    cl.popBack();
    cl.removeElement(4);

    std::cout << "Updated List: ";
    cl.print();

    return 0;
}
