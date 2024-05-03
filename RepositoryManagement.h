#ifndef REPOSITORYMANAGEMENT_H
#define REPOSITORYMANAGEMENT_H
#include<string>
using namespace std;

struct FileNode 
{
	string fileName;
	FileNode* next;
	FileNode(string name)
	{
		fileName = name;
		next = NULL;
	}
};


//this structure will hold the content of the each commit node
struct commit
{
	string commitMsg; //this will store the message that the user will provide with each commit 
	commit* next;
	FileNode* fileHead;

	//constructor
	commit(string msg)
	{
		commitMsg = msg;
		next = NULL;
		fileHead = NULL;
	}
};

//this structure will hold the content of the each repository node
struct Repository
{
	string RepoName;
	bool isPublic;
	Repository* left,*right;
	commit* commitHead;

	//constructor 
	Repository(string name, bool visibilty)
	{
		RepoName = name;
		isPublic = visibilty;
		commitHead = NULL;
		left = right = NULL;
	}
};

void initializeRepo();
Repository* CreateRepo(Repository* root, const string &RepoName, bool isPublic);
void DeleteRepo(Repository* &root,const string&RepoName);
void AddCommit(Repository* repo,const string& commitMsg,const string fileName);
void displayRepositories(Repository* root);

#endif 
