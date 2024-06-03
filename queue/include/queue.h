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