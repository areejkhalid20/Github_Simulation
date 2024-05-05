#include "FileManagement.h"
#include "RepositoryManagement.h"
#include "UserManagement.h"

void AddFile(Repository* repo, const string& fileName)
{
    if (!repo || !repo->commitHead) return; // Ensure repo and the last commit exist

    // Create a new file node
    FileNode* newFile = new FileNode(fileName);
    // Add to the start of the commit's file list
    newFile->next = repo->commitHead->fileHead;
    repo->commitHead->fileHead = newFile;
}


void DeleteFile(Repository* repo, const string& fileName)
{
    if (!repo || !repo->commitHead || !repo->commitHead->fileHead) return;

    FileNode* curr = repo->commitHead->fileHead;
    FileNode* prev = nullptr;

    while (curr)
    {
        if (curr->fileName == fileName)
        {
            if (prev)
                prev->next = curr->next;
            else
                repo->commitHead->fileHead = curr->next;

            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
