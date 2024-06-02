#ifndef HASHTABLE_NODE_H
#define HASHTABLE_NODE_H

#include <string>
#include <node.h>

using namespace std;

class HashTable_Node: public Node
{
private: 
    string key;
public:
    HashTable_Node * next;
    HashTable_Node(string key_, int value_);
    string getKey();
};

#endif // HASHTABLE_NODE_H