#include "RepositoryManagement.h"
#include "FileManagement.h"
#include <iostream>
using  namespace std;

int main() 
{
    Repository* myRepo = new Repository("ExampleRepo", true);

    //creating a commit in the repository
    commit* initialCommit = new commit("Initial commit");
    myRepo->commitHead = initialCommit;

    //adding files to the commit
    AddFile(myRepo, "file1.txt");
    AddFile(myRepo, "file2.txt");

    FileNode* cursor = myRepo->commitHead->fileHead;
    cout << "Files in the commit:" << endl;
    while (cursor)
    {
        cout << cursor->fileName << endl;
        cursor = cursor->next;
    }

    DeleteFile(myRepo, "file1.txt");

    cursor = myRepo->commitHead->fileHead;
    cout << "Files after deletion:" << endl;
    while (cursor) 
    {
        cout << cursor->fileName << endl;
        cursor = cursor->next;
    }

    while (myRepo->commitHead->fileHead) 
    {
        FileNode* temp = myRepo->commitHead->fileHead;
        myRepo->commitHead->fileHead = temp->next;
        delete temp;
    }
    delete initialCommit;
    delete myRepo;
}
