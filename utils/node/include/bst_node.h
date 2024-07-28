#ifndef BST_NODE_H
#define BST_NODE_H

namespace bst
{
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
} // namespace bst

#endif // BST_NODE_H