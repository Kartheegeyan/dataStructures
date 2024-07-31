#include <iostream>
#include "node.h"


class Stack
{
private:
    Node * top;
    int height;
public:
    Stack();
    Stack(int value);
    ~Stack();
    int getTop();
    int getHeight();
    void printStack();
    void push(int value);
    int pop();
};