#include "bst_node.h"

using namespace bst;

Node::Node(int value_) {
  this->value = value_;
  left, right = nullptr;
}

int Node::getValue() { return this->value; }

void Node::setValue(int value_) { this->value = value_; }