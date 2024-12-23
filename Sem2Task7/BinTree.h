#ifndef SEM2TASK7_BINTREE_H
#define SEM2TASK7_BINTREE_H

#include <cstdlib>

namespace Lessons {

    struct Node{
        int value;
        Node* left{nullptr};
        Node* right{nullptr};
        int weight{rand()%3 - 1};
    };

    class BinTree {
        Node* root = nullptr;
    public:
        void Add(int value);
        int Pop(int value);
        void show();
        bool FindEvenWithZeroWeight();
    };

} // Lessons

#endif //SEM2TASK7_BINTREE_H
