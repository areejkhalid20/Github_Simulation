#include "FileManagement.h"
#include "RepositoryManagement.h"
#include "UserManagement.h"

//this file is used to add files to the repository 
void AddFile(Repository* repo, const string& fileName)
{
    if (!repo || !repo->commitHead)
    {
        return;
    }

    FileNode* newFile = new FileNode(fileName);
    //adding to the start of the commit's file list
    newFile->next = repo->commitHead->fileHead;
    repo->commitHead->fileHead = newFile;
}
//this file is used to delete files from the repository
void deleteFileFromRepo(Repository* repo, const string& fileName) 
{
    if (!repo || !repo->commitHead || !repo->commitHead->fileHead)
    {
        return;
    }

    FileNode* curr = repo->commitHead->fileHead;
    FileNode* prev = nullptr;

    while (curr) 
    {
        if (curr->fileName == fileName) 
        {
            if (prev) 
            {
                prev->next = curr->next;
            }
            else 
            {
                repo->commitHead->fileHead = curr->next;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}