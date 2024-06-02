#include "hashTable_node.h"

HashTable_Node::HashTable_Node(string key_, int value_)
: Node(value_), key(key_) {}

string HashTable_Node::getKey()
{
    return key;
}
