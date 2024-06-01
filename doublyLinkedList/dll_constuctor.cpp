#include <iostream>
#include "doublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(int value)
{
    DLL_Node * newNode = new DLL_Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

DoublyLinkedList::~DoublyLinkedList() 
{
    DLL_Node* temp = head;
    while (head) {
        head = dynamic_cast<DLL_Node*>(head->next);
        delete temp;
        temp = head;
    }
}

void DoublyLinkedList::printList()
{
    DLL_Node * temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->getValue() << std::endl;
        temp = dynamic_cast<DLL_Node*>(temp->next);
    }
}

void DoublyLinkedList::getHead()
{
    if (head == nullptr)
    {
        std::cout << "Head: " << "nullptr" << std::endl;    
    }
    else
    {
        std::cout << "Head: " << this->head->getValue() << std::endl; 
    }
}

void DoublyLinkedList::getTail()
{
    if (tail == nullptr)
    {
        std::cout << "Tail: " << "nullptr" << std::endl;    
    }
    else
    {
        std::cout << "Tail: " << this->tail->getValue() << std::endl;    
    }
}

void DoublyLinkedList::getLength()
{
    std::cout << "Length: " << this->length << std::endl; 
}

void DoublyLinkedList::append(int value)
{
    DLL_Node * newNode = new DLL_Node(value);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else 
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    length++;
}

void DoublyLinkedList::deleteLast()
{
    if (length == 0)
    {
        return;
    }
    DLL_Node * temp = tail;
    if (length == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else 
    {
        tail = dynamic_cast<DLL_Node*>(tail->prev);
        tail->next = nullptr;
    }
    delete temp;
    length--;
}

void DoublyLinkedList::prepend(int value)
{
    DLL_Node * newNode = new DLL_Node(value);
    if (length == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    length++;
}

void DoublyLinkedList::deleteFirst()
{
    if (length == 0)
    {
        return;
    }
    DLL_Node * temp = head;
    if (length == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = dynamic_cast<DLL_Node*>(head->next);
        head->prev = nullptr;
    }
    delete temp;
    length--;
}

DLL_Node * DoublyLinkedList::get(int index)
{
    if (index < 0 || index >= length)
    {
        return nullptr;
    }
    int div = length / 2;
    int it;
    DLL_Node * temp;
    if (index < div)
    {
        temp = head;
        it = 0;
    }
    else 
    {
        temp = tail;
        it = length - 1;
    }
    while (it != index)
    {
        if (index < div) // First half of the DLL
        {
            temp = dynamic_cast<DLL_Node*>(temp->next);
            it++;
        }
        else // Second half of DLL
        {
            temp = dynamic_cast<DLL_Node*>(temp->prev);
            it--;
        }
    }
    return temp;
}

bool DoublyLinkedList::set(int index, int value)
{
    DLL_Node * temp = get(index);
    if (temp == nullptr)
    {
        return false;
    }
    temp->setValue(value);
    return true;
}

bool DoublyLinkedList::insert(int index, int value)
{
    if (index < 0 || index > length)
    {
        return false;
    }
    else if (index == 0)
    {
        prepend(value);
        return true;
    }
    else if (index == length)
    {
        append(value);
        return true;
    }
    else
    {
        DLL_Node * newNode = new DLL_Node(value);
        DLL_Node * bef = get(index - 1);
        // Node * curr = get(index); // get() function is O(n)
        DLL_Node * curr = dynamic_cast<DLL_Node*>(bef->next);     // This way its O(1)
        newNode->next = curr;
        newNode->prev = bef;
        bef->next = newNode;
        curr->prev = newNode;
        length++;
        return true;
    }
}

void DoublyLinkedList::deleteNode(int index)
{
    if (index < 0 || index >= length)
    {
        return;
    }
    else if (index == 0)
    {
        deleteFirst();
    }
    else if (index == length - 1)
    {
        deleteLast();
    }
    else
    {
        DLL_Node * temp = get(index);
        DLL_Node * bef = dynamic_cast<DLL_Node*>(temp->prev);
        DLL_Node * aft = dynamic_cast<DLL_Node*>(temp->next);

        bef->next = aft;
        aft->prev = bef;
        delete temp;
        length--;   
    }
}
