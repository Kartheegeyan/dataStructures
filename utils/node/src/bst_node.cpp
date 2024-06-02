#include "bst_node.h"

Node::Node(int value_)
{
    this->value = value_;
    left, right = nullptr;
}

int Node::getValue()
{
    return value;
}

void Node::setValue(int value_)
{
    this->value = value_;
}