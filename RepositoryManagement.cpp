#include "RepositoryManagement.h"

Repository::Repository(string name, bool visibility)
{
    repoName = name;
    isPublic = visibility;
    forkCount = 0;
    headCommit = NULL;
    fileHead = NULL;

}

//this function will be used to add a commitr 
void Repository::addCommit(string message, string time)
{
    Commit* newCommit = new Commit(message, time, headCommit);
    headCommit = newCommit;
}

//this is used to add a file 
void Repository::addFile(string name, string content)
{
    File* newFile = new File(name, content);
    newFile->next = fileHead;
    fileHead = newFile;
}
