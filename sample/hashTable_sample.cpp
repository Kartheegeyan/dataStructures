#include "hashTable.h"

int main()
{
    HashTable_Node * newNode = new HashTable_Node("horses", 20);
    HashTable_Node * secondNode = new HashTable_Node("dogs", 2);
    HashTable * newTable = new HashTable();

    newTable->set("horses", 20);
    newTable->set("dogs", 2);
    newTable->set("sheeps", 25);

    vector<string> myKeys = newTable->key();
    for (string key : myKeys)
    {
        std::cout << key << " ";
    }
    std:: cout << std::endl;

    // std::cout << "Value: " << newTable->get("horses") << std::endl;
    // std::cout << "Value: " << newTable->get("dogs") << std::endl;
    // std::cout << "Value: " << newTable->get("sheeps") << std::endl;

    newTable->printTable();

    // std::cout << "Hash number: " << newTable->hash("horses") << std::endl;
    // std::cout << "Key: " << newNode->getKey() << std::endl;
    // std::cout << "Value: " << newNode->getValue() << std::endl;
    // std::cout << "Next: " << newNode->next->getKey() << std::endl;

    return 0;
}