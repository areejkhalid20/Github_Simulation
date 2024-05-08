#ifndef GITHUBSIMULATION_H
#define GITHUBSIMULATION_H
#include "HashTable.h"

class GitHubSimulation
{
public:
    HashTable users;
    const string USER_FILE;

public:
    GitHubSimulation();
    void registerUser(string username, string password);
    bool login(string username, string password);
    void logout();
    void viewProfile(string username);
    void loadUsersFromCSV(string filename);
    void saveUserToFile(string username, string password);
    void createRepository(string username);
    void addCommitToRepository(string username);
    void addFileToRepository(string username);
    void deleteRepository(string username);
    void forkRepository(string username);
    void makeRepositoryPublic(string username);
    void makeRepositoryPrivate(string username);
    void viewRepositoryStats(string username);
};

#endif 
