#include <iostream>
#include "node.h"

class Queue
{
private:
    Node * first;
    Node * last;
    int length;
public:
    Queue();
    Queue(int value);
    ~Queue();
    void printQueue();
    Node * getFirst();
    Node * getLast();
    int getLength();
    void enqueue(int value);
    int dequeue();
};

Queue::Queue()
{
    first, last = nullptr;
    length = 0;
}

Queue::Queue(int value)
{
    Node * newNode = new Node(value);
    first = newNode;
    last = newNode;
    length = 1;
}

Queue::~Queue()
{
    Node * temp = first;
    while (first != nullptr)
    {
        first = first->next;
        delete temp;
        temp = first;
    }
}

void Queue::printQueue()
{
    Node * temp = first;
    for (int i = 0; i < length; i++)
    {
        std::cout << temp->getValue() << std::endl;
        temp = temp->next;
    }  
    std::cout << std::endl;
}

Node * Queue::getFirst()
{
    return first;
}

Node * Queue::getLast()
{
    return last;
}

int Queue::getLength()
{
    return length;
}

void Queue::enqueue(int value_)
{
    Node * newNode = new Node(value_);
    if (first == nullptr)
    {
        first, last = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
    length++;
}

int Queue::dequeue()
{
    if (first == nullptr) { return INT16_MIN; }

    Node * temp = first;
    int dQ_value = first->getValue();
    if (length == 1)
    {
        first = nullptr;
        last = nullptr;    
    }
    else
    {
        first = first->next;
    }
    delete temp;
    length--;
    return dQ_value;
}



int main()
{
    Queue * newQueue = new Queue(1);
    newQueue->enqueue(2);
    newQueue->enqueue(3);
    // newQueue->dequeue();
    // newQueue->dequeue();
    
    newQueue->printQueue();
    std::cout <<"first: " << newQueue->getFirst()->getValue() << std::endl;    
    std::cout <<"last: " << newQueue->getLast()->getValue() << std::endl;
    std::cout <<"Length: " << newQueue->getLength() << std::endl;

    return 0;
}