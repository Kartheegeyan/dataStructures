#include "tree.h"

using namespace bst;

BinarySearchTree::BinarySearchTree() { root = nullptr; }

BinarySearchTree::BinarySearchTree(int value_) {
  Node* rootNode = new Node(value_);
  root = rootNode;
}

Node* BinarySearchTree::getRoot() { return root; }

int BinarySearchTree::getRootValue() { return root->getValue(); }

bool BinarySearchTree::insert(int value_) {
  Node* newNode = new Node(value_);
  if (root == nullptr) {
    root = newNode;
    return true;
  }
  Node* temp = root;
  while (true) {
    if (temp->getValue() == newNode->getValue()) {
      return false;
    }
    if (newNode->getValue() < temp->getValue()) {
      if (temp->left == nullptr) {
        temp->left = newNode;
        return true;
      }
      temp = temp->left;
    } else  // newNode->getValue() > temp->getValue()
    {
      if (temp->right == nullptr) {
        temp->right = newNode;
        return true;
      }
      temp = temp->right;
    }
  }
}

bool BinarySearchTree::contains(int value_) {
  Node* temp = root;
  while (temp != nullptr) {
    if (temp->getValue() == value_) {
      return true;
    } else if (value_ < temp->getValue()) {
      temp = temp->left;
    } else  // value_ < temp->getValue()
    {
      temp = temp->right;
    }
  }
  return false;
}

void BinarySearchTree::displayTree() {
  Node* temp = root;
  Node* temp_R;
  if (temp == nullptr) {
    return;
  }
  std::cout << "----- Tree -----" << std::endl;
  std::cout << root->getValue() << std::endl;

  while (temp->left != nullptr && temp_R->right != nullptr) {
    temp_R = temp->right;
    temp = temp->left;

  }
}