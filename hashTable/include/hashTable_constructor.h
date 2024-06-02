#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include "hashTable_node.h"

class HashTable
{
private:
    static const int SIZE = 7; // Better to use prime numbers
    HashTable_Node * dataMap[SIZE];
public:
    void printTable();
    int hash(string key);
    void set(string key, int value);
    int get(string key);
    vector<string> key();
    void update(string key, int value);
};

#endif // HASHTABLE_H
