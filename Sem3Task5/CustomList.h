#include <iostream>
#include <list>
#include <algorithm>
#include <stdexcept>

#ifndef SEM3TASK5_CUSTOMLIST_H
#define SEM3TASK5_CUSTOMLIST_H

template<typename T>
class CustomList {
private:
    std::list<T> lst;

public:
    void pushFront(const T &element) {
        lst.push_front(element);
    }

    void pushBack(const T &element) {
        lst.push_back(element);
    }

    void insertBefore(const T &target, const T &element) {
        auto it = std::find(lst.begin(), lst.end(), target);
        if (it != lst.end()) {
            lst.insert(it, element);
        } else {
            std::cerr << "Element " << target << " not found.\n";
        }
    }

    void insertAfter(const T &target, const T &element) {
        auto it = std::find(lst.begin(), lst.end(), target);
        if (it != lst.end()) {
            lst.insert(++it, element);
        } else {
            std::cerr << "Element " << target << " not found.\n";
        }
    }

    T pop() {
        if (lst.empty()) {
            throw std::out_of_range("List is empty");
        }
        T firstElement = lst.front();
        lst.pop_front();
        return firstElement;
    }

    T popBack() {
        if (lst.empty()) {
            throw std::out_of_range("List is empty");
        }
        T lastElement = lst.back();
        lst.pop_back();
        return lastElement;
    }

    void removeElement(const T &element) {
        lst.remove(element);
    }

    void print() const {
        for (const auto &el: lst) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
};

#endif //SEM3TASK5_CUSTOMLIST_H
