#include "dll_node.h"

DLL_Node::DLL_Node(int value_) : Node(value_)
{
    this->prev = nullptr;
}