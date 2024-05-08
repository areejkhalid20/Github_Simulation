#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "Commit.h"
#include "FileManagement.h"

class Repository
{
public:
    string repoName;
    bool isPublic;
    int forkCount;
    Commit* headCommit;
    File* fileHead;

    Repository(string name, bool visibility);
    void addCommit(string message, string time);
    void addFile(string name, string content);
};

#endif 
