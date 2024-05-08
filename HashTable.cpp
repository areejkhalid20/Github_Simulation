#include "HashTable.h"

HashTable::HashTable() 
{
    for (int i = 0; i < 101; ++i)
    {
        table[i] = NULL;
    }
}

HashTable::~HashTable() 
{
    for (int i = 0; i < 101; ++i)
    {
        if (table[i] != NULL) 
        {
            delete table[i];
        }
    }
}

//hash function to store the keys effeciently 
int HashTable::hash(string key)
{
    int hashVal = 0;
    for (char c : key)
    {
        hashVal += c;
    }
    return hashVal % 101;
}

void HashTable::insertUser(string username, string password) 
{
    int index = hash(username);
    while (table[index] != NULL) 
    {
        index = (index + 1) % 101;
    }
    table[index] = new User(username, password);
}

User* HashTable::findUser(string username)
{
    int index = hash(username);
    while (table[index] != nullptr && table[index]->username != username) 
    {
        index = (index + 1) % 101;
    }
    return table[index];
}
