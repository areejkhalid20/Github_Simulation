//handling user operation like login register and viewing profile 
#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H
#include<string>

using namespace std;

void initUserTable();
bool RegisterUser(const string& username, const string& password);
bool LoginUser(const string& username, const string& password);
void ViewProfile(const string& username);

#endif


