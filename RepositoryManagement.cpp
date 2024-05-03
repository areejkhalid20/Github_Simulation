//implementation of functions
#include "RepositoryManagement.h"
#include<iostream>
using namespace std;

Repository* repoHead = NULL;

//initialziw the repository 
void initializeRepo()
{
	repoHead = NULL;
}

//this function will create a repository 
Repository* CreateRepo(Repository* root, const string& RepoName, bool isPublic)
{
    if(root==NULL)
    {
        return new Repository(RepoName, isPublic); //create node if empty 
    }
    if (RepoName < root->RepoName) //lesser values goes to the left subtree
    {
        root->left = CreateRepo(root->left, RepoName, isPublic);
    }
    else if (RepoName > root->RepoName) //greater values goes to the left subtree
    {
        root->right = CreateRepo(root->right, RepoName, isPublic);
    }
    return root;
}
//helper function to used for deletion 
Repository* findMin(Repository* root)
{
    while (root && root->left != NULL) 
    {
        root = root->left;
    }
    return root;
}

//this function will be used to delete a repository from the tree
Repository* deleteRepository(Repository* root, const string& RepoName)
{
    if (root == nullptr) 
    {
        return root;
    }
    if (RepoName < root->RepoName)
    {  //search in the left subtree
        root->left = deleteRepository(root->left, RepoName);
    }
    else if (RepoName > root->RepoName) 
    {  //search in the right subtree
        root->right = deleteRepository(root->right, RepoName);
    }
    else 
    {
        //one child or no child
        if (root->left == nullptr) 
        {
            Repository* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) 
        {
            Repository* temp = root->left;
            delete root;
            return temp;
        }
        //two children case
        Repository* temp = findMin(root->right);
        root->RepoName = temp->RepoName;
        root->commitHead = temp->commitHead;  
        root->right = deleteRepository(root->right, temp->RepoName);
    }
    return root;
}

//this function will be used to add a commit 
void AddCommit(Repository* repo, const string& commitMsg, const string fileName)
{
    if (!repo) //incase the repo doesnt exist 
    {
        return;
    }
    //create new commit node 
    commit* newCommit = new commit(commitMsg);
    newCommit->next = repo->commitHead;
    repo->commitHead = newCommit;
    FileNode* newFile = new FileNode(fileName);
    newFile->next = newCommit->fileHead;
    newCommit->fileHead = newFile;
}

//this function will be used to display the repostitories in in-order traversal
void displayRepositories(Repository*root) 
{
    if (!root)
    {
        return;
    }
    displayRepositories(root->left);
    cout << "Repository: " << root->RepoName << (root->isPublic ? " (Public)" : " (Private)") << endl;
    displayRepositories(root->right);
}