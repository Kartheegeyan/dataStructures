#include <iostream>

#include <node.h>

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value);

    ~LinkedList();

    void printList();

    void getHead();

    void getTail();

    void getLength();

    void append(int value);

    void deleteLast();

    void prepend(int value);

    void deleteFirst();

    Node *get(int index);

    bool set(int index, int new_value);

    bool insert(int index, int value);

    void deleteNode(int index);

    void reverse();
};