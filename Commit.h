#ifndef COMMIT_H
#define COMMIT_H

#include <string>

using namespace std;

class Commit 
{
public:
    string commitMessage;
    string timestamp;
    Commit* parent;
    Commit* child;

    Commit(string message, string time, Commit* p);
};

#endif 
