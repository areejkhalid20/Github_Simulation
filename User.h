#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User 
{
public:
    string username;
    //default constructor
    User()
    {
        username = "";
    }
    //parameterized constructor 
    User(string username)
    {
        username = username;
    }
};

#endif
