#ifndef BINARYTRIES_BINARYTREE_H
#define BINARYTRIES_BINARYTREE_H

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

void InitTree(Node* node);
void addElement(Node* node, int value);
void deleteElement(Node* node, int value);
void find(Node* node, int value);

#endif //BINARYTRIES_BINARYTREE_H
