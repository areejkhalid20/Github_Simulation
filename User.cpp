#include "User.h"

User::User(string uname, string pwd) 
{
    username = uname;
    password = pwd;
    followers = NULL;
    repositories = new Repository * [100];
    numFollowers = 0;
    numRepositories = 0;

    for (int i = 0; i < 100; ++i) 
    {
        repositories[i] = nullptr;
    }
}

User::~User() 
{
    delete followers;
    for (int i = 0; i < numRepositories; ++i) 
    {
        delete repositories[i];
    }
    delete[] repositories;
}
