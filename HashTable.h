#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "User.h"

class HashTable 
{
private:
    User* table[101];

public:
    HashTable();
    ~HashTable();
    int hash(string key);
    void insertUser(string username, string password);
    User* findUser(string username);
};

#endif 
