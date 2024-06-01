#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "bst_node.h"

class BinarySearchTree
{
private:
    Node * root;
public:
    int size;
    BinarySearchTree();
    BinarySearchTree(int value);
    Node * getRoot();
    int getRootValue();
    bool insert(int value);
    bool contains(int value_);
};

#endif // BINARYSEARCHTREE_H
