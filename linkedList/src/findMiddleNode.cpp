#include <iostream>

using namespace std;


class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        int getHead() {
            if (head == nullptr) {
                return -1;
            } else {
                return head->value;
            }
        }

        int getTail() {
            if (tail == nullptr) {
                return -1;
            } else { 
                return tail->value;
            }  
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        /*  Implement a member function, findMiddleNode(), which finds and returns the middle node of the linked list.

            Note: this LinkedList implementation does not have a length member variable.
        */

       /* 
            This problem is solved using the tortoise and hare algorithm. Since the fast pointer moves twice as fast as the slow pointer,
            when the fast pointer reaches the end of the linkedList the slow pointer will be at the middle node.
       */
        
        Node* findMiddleNode()
        {
            Node * fast = head;
            Node * slow = head;
            while (fast != nullptr && fast->next != nullptr)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }
};


int main() {
        
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    myLinkedList->append(6);
    myLinkedList->append(7);
    cout << myLinkedList->findMiddleNode()->value <<endl;
}