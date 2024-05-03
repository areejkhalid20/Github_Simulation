//handling user operation like login register and viewing profile 
#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H
#include "RepositoryManagement.h"
#include<string>

using namespace std;

void initUserTable();
void initializeRepo();
Repository* CreateRepo(Repository* root, const string& RepoName, bool isPublic);
void DeleteRepo(Repository*& root, const string& RepoName);
void AddCommit(Repository* repo, const string& commitMsg, const string fileName);
void displayRepositories(Repository* root);

bool RegisterUser(const string& username, const string& password);
bool LoginUser(const string& username, const string& password);
void ViewProfile(const string& username);

#endif


