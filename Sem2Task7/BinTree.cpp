#include <iostream>
#include <iomanip>
#include "BinTree.h"

namespace Lessons {
    void AddValueToNode(Node **node, int value) {
        if (!*node) {
            *node = new Node{value};
        } else {
            if (value > (*node)->value) {
                AddValueToNode(&((*node)->right), value);
            } else {
                AddValueToNode(&((*node)->left), value);
            }
        }
    }

    bool FindEvenNodeWithZeroWeight(Node *node) {
        if (node == nullptr) {
            return false;
        } else if (!(node->value % 2) and node->weight == 0) {
            return true;
        } else {
            return FindEvenNodeWithZeroWeight(node->left) or FindEvenNodeWithZeroWeight(node->right);
        }
    }

    void BinTree::Add(int value) {
        AddValueToNode(&root, value);
    }

    bool BinTree::FindEvenWithZeroWeight() {
        return FindEvenNodeWithZeroWeight(root);
    }

    Node **FindNodeWithValue(int value, Node **node) {

        if (*node == nullptr or (*node)->value == value) {
            return node;
        } else {
            Node **tmp = FindNodeWithValue(value, &((*node)->left));
            if (tmp and (*tmp)) {
                return FindNodeWithValue(value, &((*node)->left));
            } else {
                tmp = FindNodeWithValue(value, &((*node)->right));
                if ((*tmp)) {
                    return FindNodeWithValue(value, &((*node)->right));
                } else {
                    return nullptr;
                }
            }
        }
    }

    Node **FindMax(Node **node) {
        if ((*node)->right) {
            return FindMax(&((*node)->right));
        } else {
            return node;
        }
    }

    int BinTree::Pop(int value) {
        Node **tmp = FindNodeWithValue(value, &root);
        if ((*tmp)->left) {
            Node **tmp1 = FindMax(&((*tmp)->left));
            (*tmp)->value = (*tmp1)->value;
            (*tmp)->weight = (*tmp1)->weight;
            Node *left = (*tmp1)->left;
            delete *tmp1;
            *tmp1 = left;
            return value;
        } else if ((*tmp)->right) {
            Node *right = (*tmp)->right;
            delete *tmp;
            *tmp = right;
            return value;
        } else if (!((*tmp)->right) and !((*tmp)->left)) {
            delete *tmp;
            *tmp = nullptr;
            return value;
        }
    }

    void showTree(Node *t, int n) {
        if (t != nullptr) {
            showTree(t->left, n + 1);
            std::cout << std::setw(n * 5) << t->value << "(" << t->weight << ")" << std::endl;
            showTree(t->right, n + 1);
        }
    }

    void BinTree::show() {
        showTree(root, 1);
    }
} // Lessons