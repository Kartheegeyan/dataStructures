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

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail;
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
    
        Node* findKthFromEnd(int k) {
            Node * fast = head;
            Node * slow = head;
            // Set fast k nodes ahead of slow
            for (int i = 0; i < k; i++)
            {
                if (fast != nullptr)
                {
                    fast = fast->next;
                }
                else 
                {
                    return nullptr;
                }
            }
            while (fast != nullptr)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    
};

int main()
{
    LinkedList* newLinkedList = new LinkedList(1);
    newLinkedList->append(2);
    newLinkedList->append(3);
    newLinkedList->append(4);
    newLinkedList->append(5);
    cout << newLinkedList->findKthFromEnd(4)->value << endl;;

}