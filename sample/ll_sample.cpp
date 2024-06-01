#include <iostream>

#include <linkedList_constructor.h>

using namespace std;

int main() {
        
    LinkedList* myLinkedList = new LinkedList(0);

    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->insert(1,1);

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    
    cout << "\nLinked List:\n";
    myLinkedList->printList();

    myLinkedList->reverse();

    myLinkedList->printList();

    /*  
        EXPECTED OUTPUT:
    	----------------
        Head: 4
        Tail: 4
        Length: 1

        Linked List:
        4

    */
       
}