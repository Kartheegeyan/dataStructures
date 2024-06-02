#ifndef BST_NODE_H
#define BST_NODE_H

class Node
{
private:
    int value;
public:
    Node * left;
    Node * right;
    Node(int value_);
    int getValue();
    void setValue(int value_);
};

#endif // BST_NODE_H