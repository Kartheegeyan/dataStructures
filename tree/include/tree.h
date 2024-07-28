#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include "bst_node.h"

class BinarySearchTree {
 private:
  bst::Node* root;

 public:
  int size;
  BinarySearchTree();
  BinarySearchTree(int value);
  bst::Node* getRoot();
  int getRootValue();
  bool insert(int value);
  bool contains(int value_);
  void displayTree();
};

#endif  // BINARYSEARCHTREE_H
