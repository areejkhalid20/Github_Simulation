#include "UserGraph.h"
#include <iostream>


UserGraph::UserGraph() : userCount(0) 
{
    for (int i = 0; i < MAX_USERS; i++)
    {
        relationships[i] = NULL;
    }
}


int UserGraph::addUser(string username)
{
    if (userCount < MAX_USERS) 
    {
        users[userCount] = User(username);
        userCount++;
        return userCount - 1; //this will return the index of the new user 
    }
    return -1;
}

//this function will be used to follow a user 
void UserGraph::follow(int followerIndex, int followingIndex) 
{
    Node* newNode = new Node(followingIndex);
    newNode->next = relationships[followerIndex];
    relationships[followerIndex] = newNode;
}

void UserGraph::unfollow(int followerIndex, int followingIndex) 
{
    Node* current = relationships[followerIndex];
    Node* prev = NULL;
    while (current != NULL)
    {
        if (current->userIndex == followingIndex) 
        {
            if (prev == NULL) 
            {
                relationships[followerIndex] = current->next;
            }
            else 
            {
                prev->next = current->next;
            }
            delete current;
            break;
        }
        prev = current;
        current = current->next;
    }
}
//printing the users 
void UserGraph::printFollowers(int userIndex) 
{
    Node* current = relationships[userIndex];
    cout << "Users followed by " << users[userIndex].username << ": ";
    while (current != NULL)
    {
        cout << users[current->userIndex].username << " ";
        current = current->next;
    }
    cout << endl;
}
