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
Repository* findMin(Repository* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a repository from the binary search tree
Repository* deleteRepository(Repository* root, const std::string& RepoName) {
    if (root == nullptr) {
        return nullptr;  // Not found
    }
    if (RepoName < root->RepoName) {
        root->left = deleteRepository(root->left, RepoName);  // Search in the left subtree
    }
    else if (RepoName > root->RepoName) {
        root->right = deleteRepository(root->right, RepoName);  // Search in the right subtree
    }
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Repository* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Repository* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor
        Repository* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->RepoName = temp->RepoName;
        root->commitHead = temp->commitHead;

        // Delete the inorder successor
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

Repository* findRepository(Repository* root, const std::string& RepoName) {
    if (root == nullptr) {
        return nullptr;  // Base case: repository not found
    }
    if (RepoName < root->RepoName) {
        return findRepository(root->left, RepoName);  // Search in the left subtree
    }
    else if (RepoName > root->RepoName) {
        return findRepository(root->right, RepoName);  // Search in the right subtree
    }
    else {
        return root;  // Repository found
    }
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