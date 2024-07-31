#include "stack.h"

Stack::Stack() : top(nullptr), height(0) {}

Stack::Stack(int value)
{
    Node * newNode  = new Node(value);
    top = newNode;
    height = 1;
}

Stack::~Stack()
{
    Node* temp = top;
    while (top) {
        top = top->next;
        delete temp;
        temp = top;
    }
}

int Stack::getTop()
{
    return top->getValue();
}

int Stack::getHeight()
{
    return height;
}


void Stack::printStack()
{
    Node * temp = top;
    for (int i = 0; i < height; i++)
    {
        std::cout << temp->getValue() << std::endl;
        temp = temp->next;
    }
    
}

void Stack::push(int value_)
{
    Node * newNode = new Node(value_);
    newNode->next = top;
    top = newNode;
    height++;
}

int Stack::pop()
{
    if (height == 0)
    {
        return INT8_MIN; // This represents the smallest 8bit integer value (-128).
    }
    if (height == 1)
    {
        top = nullptr;
    }
    
    Node * temp = top;
    int poppedValue = temp->getValue();
    top = top->next;
    delete temp;
    height--;

    return poppedValue;
}