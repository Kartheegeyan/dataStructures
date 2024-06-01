#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "dll_node.h"

class DoublyLinkedList
{
private:
    DLL_Node * head;
    DLL_Node * tail;
    int length;

public:
    DoublyLinkedList(int value);
    ~DoublyLinkedList();
    void printList();
    void getHead();
    void getTail();
    void getLength();
    void append(int value);
    void deleteLast();
    void prepend(int value);
    void deleteFirst();
    DLL_Node * get(int index);
    bool set(int index, int value);
    bool insert(int index, int value);
    void deleteNode(int index);
};
#endif // DOUBLYLINKEDLIST_H