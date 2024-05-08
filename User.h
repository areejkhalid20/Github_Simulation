#ifndef USER_H
#define USER_H
#include "RepositoryManagement.h"

class User 
{
public:
    string username;
    string password;
    User* followers;
    Repository** repositories;
    int numFollowers;
    int numRepositories;

    User(string uname, string pwd);
    ~User();
};

#endif 
