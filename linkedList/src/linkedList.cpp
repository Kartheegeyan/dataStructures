#include <iostream>

#include <linkedList.h>

using namespace std;

LinkedList::LinkedList(int value)
{
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

LinkedList::~LinkedList()
{
    Node *temp = head;
    while (head)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void LinkedList::printList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->getValue() << endl;
        temp = temp->next;
    }
}

void LinkedList::getHead()
{
    if (head == nullptr)
    {
        cout << "Head: nullptr" << endl;
    }
    else
    {
        cout << "Head: " << head->getValue() << endl;
    }
}

void LinkedList::getTail()
{
    if (tail == nullptr)
    {
        cout << "Tail: nullptr" << endl;
    }
    else
    {
        cout << "Tail: " << tail->getValue() << endl;
    }
}

void LinkedList::getLength()
{
    cout << "Length: " << length << endl;
}

void LinkedList::append(int value)
{
    Node *newNode = new Node(value);
    if (this->length == 0)
    {
        head = newNode;
        tail = newNode;
    }

    else if (this->length > 0)
    {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::deleteLast()
{
    if (length == 0)
    {
        head = nullptr;
        tail = nullptr;
    }
    else if (length == 1)
    {
        delete head, tail;
        head = nullptr;
        tail = nullptr;
    }
    else // length is > 1
    {
        Node *temp = head;
        Node *prev = head;
        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        tail = prev;
        tail->next = nullptr;
        delete temp;
    }
    // To avoid negative length values
    if (length > 0)
        length--;
}

void LinkedList::prepend(int value)
{
    Node *newNode = new Node(value);
    if (length == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    length++;
}

void LinkedList::deleteFirst()
{
    Node *temp = head;
    if (length == 0)
    {
        return;
    }
    else if (length == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else // length > 1
    {
        head = head->next;
    }
    delete temp;
    length--;
}

Node *LinkedList::get(int index)
{
    if (index < 0 || index >= length)
    {
        return nullptr;
    }
    else
    {
        Node *result = head;
        int it = 0;
        while (it != index)
        {
            result = result->next;
            it++;
        }
        return result;
    }
}

bool LinkedList::set(int index, int new_value)
{
    Node *temp = get(index);
    if (temp == nullptr)
    {
        return false;
    }
    else
    {
        temp->setValue(new_value);
        return true;
    }
}

bool LinkedList::insert(int index, int value)
{
    Node *newNode = new Node(value);
    Node *prev = get(index - 1);
    Node *displaced = get(index);
    if (index == 0)
    {
        prepend(value);
        return true;
    }
    else if (index == length - 1)
    {
        append(value);
        return true;
    }
    else if (prev != nullptr)
    {
        prev->next = newNode;
        newNode->next = displaced;
        length++;
        return true;
    }
    return false;
}

void LinkedList::deleteNode(int index)
{
    Node *temp = get(index);
    Node *prev = get(index - 1);
    if (index == 0) // head
    {
        deleteFirst();
    }
    else if (index == length - 1) // tail
    {
        deleteLast();
    }
    else if (temp != nullptr) // index > 0 && index < length
    {
        prev->next = temp->next;
        delete temp;
        length--;
    }
}

void LinkedList::reverse()
{
    // switch head and tail
    Node *curr = head;
    head = tail;
    tail = curr;
    // Reverse the next pointers of the nodes
    Node *prev = nullptr;
    Node *after;
    for (int i = 0; i < length; i++)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
}
