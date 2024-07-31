#include "hashTable.h"

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