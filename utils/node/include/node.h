#ifndef NODE_H
#define NODE_H

class Node
{
protected:
    int value;
public:
    Node * next;

    Node(int value_);
    virtual int getValue();
    void setValue(int value_);
};
#endif // NODE_H