#ifndef DLL_NODE_H
#define DLL_NODE_H

#include <node.h>

class DLL_Node : public Node
{
public:
    Node * prev;

    DLL_Node(int value_);
};
#endif // DLL_NODE_H