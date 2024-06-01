#include <iostream>
#include "doublyLinkedList.h"

int main()
{
    DoublyLinkedList * newDll = new DoublyLinkedList(1);
    newDll->append(2);
    newDll->append(3);
    newDll->append(4);
    // newDll->deleteNode(5);

    newDll->getHead();
    newDll->getTail();
    newDll->getLength();
    newDll->printList();
}