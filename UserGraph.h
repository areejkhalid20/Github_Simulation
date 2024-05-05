#ifndef USERGRAPH_H
#define USERGRAPH_H
#include "User.h"
using namespace std;
//This shows the maximum number of user 
const int MAX_USERS = 100;

struct Node 
{
    int userIndex;
    Node* next;

    Node(int index)
    {
        userIndex = index;
        next = NULL;
    }
};
class UserGraph 
{
private:
    User users[MAX_USERS];
    Node* relationships[MAX_USERS];
    int userCount;

public:
    UserGraph();
    int addUser(string username);
    void follow(int followerIndex, int followingIndex);
    void unfollow(int followerIndex, int followingIndex);
    void printFollowers(int userIndex);
};

#endif
