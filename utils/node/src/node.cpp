#include "node.h"

Node::Node(int value)
{
    this->value = value;
    this->next = nullptr;
}

int Node::getValue()
{
    if (this == nullptr)
    {
        return -1;
    }
    return value;
}

void Node::setValue(int value_)
{
    this->value = value_;
}