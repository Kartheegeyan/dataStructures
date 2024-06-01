#include <iostream>
#include "hashTable_constructor.h"

void HashTable::printTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << i << ":" << std::endl;
        if (dataMap[i] != nullptr)
        {
            HashTable_Node * temp = dataMap[i];
            while (temp != nullptr)
            {
                std::cout << "{Key: " << temp->getKey() << ", Value: " << temp->getValue() << "}" << std::endl;
                temp = temp->next;
            }
        }
    }
}

int HashTable::hash(std::string key)
{
    int hash = 0;
    for (int i = 0; i < key.length(); i++)
    {
        int asciiValue = int(key[i]);
        hash = (hash + asciiValue * 23) % SIZE;
    }
    return hash;
}

void HashTable::set(string key, int value)
{
    HashTable_Node * newNode = new HashTable_Node(key, value);
    int idx = hash(key);
    if (dataMap[idx] == nullptr)
    {
        dataMap[idx] = newNode;
    }
    else 
    {
        HashTable_Node * temp = dataMap[idx];
        while (temp->next != nullptr)
        {
            temp = temp->next;         
        }
        temp->next = newNode;
    }
}

int HashTable::get(string key)
{
    int idx = hash(key);
    HashTable_Node * temp = dataMap[idx];
    while (temp != nullptr)
    {
        if (temp->getKey() == key)
        {
            return temp->getValue();
        }
        temp = temp->next;
    }
    std::cout << "Invalid Key" << std::endl;
    return 0;
}

vector<string> HashTable::key()
{
    vector<string> allKeys;
    for (int i = 0; i < SIZE; i++)
    {
        HashTable_Node * temp = dataMap[i];
        while (temp != nullptr)
        {
            allKeys.push_back(temp->getKey());
            temp = temp->next;
        }
    }
    return allKeys;
}





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