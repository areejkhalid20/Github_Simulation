#include "GitHubSimulation.h"
#include "HashTable.h" 
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

GitHubSimulation::GitHubSimulation() : USER_FILE("users.csv") 
{
    loadUsersFromCSV(USER_FILE);
}

//this function will be used to register a user 
void GitHubSimulation::registerUser(string username, string password)
{
    if (users.findUser(username) != NULL) //if the user is already stored 
    {
        cout << "Username already exists. Please choose another one." << endl;
    }
    else 
    {
        users.insertUser(username, password);
        cout << "Registration successful." << endl;
        saveUserToFile(username, password);
    }
}

//this will be used as a function to log in a user into the system 
bool GitHubSimulation::login(string username, string password) 
{
    User* user = users.findUser(username);
    if (user != NULL && user->password == password)
    {
        cout << "Login successful." << endl;
        return true;
    }
    else 
    {
        cout << "Invalid username or password." << endl;
        return false;
    }
}

//this function will simply display a msg saying "Logout"
void GitHubSimulation::logout() {
    cout << "Logout successful." << endl;
}

void GitHubSimulation::viewProfile(string username)
{
    User* user = users.findUser(username);
    if (user != NULL) 
    {
        cout << "Username: " << user->username << endl;
        cout << "Followers: ";
        if (user->followers != NULL)  //to display the followers of a user if there are any 
        {
            for (int i = 0; i < user->numFollowers; ++i)
            {
                cout << user->followers[i].username << ", ";
            }
        }
        cout << endl << "Repositories:" << endl;
        for (int i = 0; i < user->numRepositories; ++i)
        {
            cout << "\t" << user->repositories[i]->repoName << endl;
        }
    }
    else 
    {
        cout << "User not found." << endl;
    }
}

//this function will be used to load the data from the file 
void GitHubSimulation::loadUsersFromCSV(string filename) 
{
    ifstream file(filename);
    if (!file.is_open()) 
    {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) 
    {
        stringstream ss(line);
        string username, password;
        getline(ss, username, ',');
        getline(ss, password, ',');
        users.insertUser(username, password);
    }

    file.close();
    cout << "User data loaded successfully from " << filename << endl;
}

//sving to the file 
void GitHubSimulation::saveUserToFile(string username, string password)
{
    ofstream file(USER_FILE, ios::out | ios::app); //opening the file in out and append mode
    if (!file.is_open())
    {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    //insert the new user info in the file 
    file << username << "," << password << endl;
    file.close();
    cout << "User data saved to file." << endl;
}

//Repository Management
void GitHubSimulation::createRepository(string username)
{
    User* user = users.findUser(username);
    if (user != nullptr && user->numRepositories < 100) 
    {
        string name;
        bool visibility;
        cout << "Enter repository name: ";
        cin >> name;
        cout << "Is the repository public? (1 for yes, 0 for no): ";
        cin >> visibility;
        user->repositories[user->numRepositories++] = new Repository(name, visibility);
        cout << "Repository \"" << name << "\" created successfully." << endl;
    }
    else
    {
        cout << "Maximum repository limit reached or user not found." << endl;
    }
}

void GitHubSimulation::addCommitToRepository(string username) 
{
    User* user = users.findUser(username);
    if (user != NULL) //if the yser exists 
    {
        string repoName, message, time;
        cout << "Enter repository name to add commit to: ";
        cin >> repoName;
        for (int i = 0; i < user->numRepositories; ++i) 
        {
            if (user->repositories[i]->repoName == repoName)
            {
                cout << "Enter commit message: ";
                cin.ignore(); // Ignore newline character left in the buffer
                getline(cin, message);
                cout << "Enter timestamp: ";
                cin >> time;
                user->repositories[i]->addCommit(message, time);
                cout << "Commit added to repository \"" << repoName << "\" successfully." << endl;
                return;
            }
        }
        cout << "Repository not found." << endl;
    }
    else
    {
        cout << "User not found." << endl;
    }
}

void GitHubSimulation::addFileToRepository(string username)
{
    User* user = users.findUser(username);
    if (user != NULL) 
    {
        string repoName, filename, content;
        cout << "Enter repository name to add file to: ";
        cin >> repoName;
        for (int i = 0; i < user->numRepositories; ++i) 
        {
            if (user->repositories[i]->repoName == repoName) 
            {
                cout << "Enter filename: ";
                cin >> filename;
                cout << "Enter file content: ";
                cin.ignore(); //ignore newline character 
                getline(cin, content);
                user->repositories[i]->addFile(filename, content);
                cout << "File added to repository \"" << repoName << "\" successfully." << endl;
                return;
            }
        }
        cout << "Repository not found." << endl;
    }
    else 
    {
        cout << "User not found." << endl;
    }
}

void GitHubSimulation::deleteRepository(string username) 
{
    User* user = users.findUser(username);
    if (user != NULL) 
    {
        string repoName;
        cout << "Enter repository name to delete: ";
        cin >> repoName;
        for (int i = 0; i < user->numRepositories; ++i)
        {
            if (user->repositories[i]->repoName == repoName)
            {
                delete user->repositories[i];
                for (int j = i; j < user->numRepositories - 1; ++j)
                {
                    user->repositories[j] = user->repositories[j + 1];
                }
                user->numRepositories--;
                cout << "Repository \"" << repoName << "\" deleted successfully." << endl;
                return;
            }
        }
        cout << "Repository not found." << endl;
    }
    else 
    {
        cout << "User not found." << endl;
    }
}

void GitHubSimulation::forkRepository(string username)
{
    User* user = users.findUser(username);
    if (user != NULL)
    {
        string name;
        cout << "Enter repository name to fork: ";
        cin >> name;
        for (int i = 0; i < user->numRepositories; ++i) 
        {
            if (user->repositories[i]->repoName == name)
            {
                user->repositories[user->numRepositories++] = new Repository(name + "_fork", user->repositories[i]->isPublic);
                user->repositories[i]->forkCount++; // Increment fork count for the original repository
                cout << "Repository \"" << name << "\" forked successfully." << endl;
                return;
            }
        }
        cout << "Repository not found." << endl;
    }
    else 
    {
        cout << "User not found." << endl;
    }
}

void GitHubSimulation::makeRepositoryPublic(string username) 
{
    User* user = users.findUser(username);
    if (user != nullptr) 
    {
        string repoName;
        cout << "Enter repository name to make public: ";
        cin >> repoName;
        for (int i = 0; i < user->numRepositories; ++i)
        {
            if (user->repositories[i]->repoName == repoName)
            {
                user->repositories[i]->isPublic = true;
                cout << "Repository \"" << repoName << "\" is now public." << endl;
                return;
            }
        }
        cout << "Repository not found." << endl;
    }
    else 
    {
        cout << "User not found." << endl;
    }
}

void GitHubSimulation::makeRepositoryPrivate(string username) 
{
    User* user = users.findUser(username);
    if (user != NULL) 
    {
        string repoName;
        cout << "Enter repository name to make private: ";
        cin >> repoName;
        for (int i = 0; i < user->numRepositories; ++i) 
        {
            if (user->repositories[i]->repoName == repoName)
            {
                user->repositories[i]->isPublic = false;
                cout << "Repository \"" << repoName << "\" is now private." << endl;
                return;
            }
        }
        cout << "Repository not found." << endl;
    }
    else
    {
        cout << "User not found." << endl;
    }
}

void GitHubSimulation::viewRepositoryStats(string username)
{
    User* user = users.findUser(username);
    if (user != NULL) 
    {
        string repoName;
        cout << "Enter repository name to view stats: ";
        cin >> repoName;
        for (int i = 0; i < user->numRepositories; ++i)
        {
            if (user->repositories[i]->repoName == repoName)
            {
                Repository* repo = user->repositories[i];
                cout << "Repository Name: " << repo->repoName << endl;
                cout << "Visibility: " << (repo->isPublic ? "Public" : "Private") << endl;
                cout << "Number of Forks: " << repo->forkCount << endl; //displaying fork count

                int commitCount = 0;
                Commit* commitPtr = repo->headCommit;
                while (commitPtr)
                {
                    commitCount++;
                    cout << "Commit " << commitCount << ": " << commitPtr->commitMessage << " - " << commitPtr->timestamp << endl;
                    commitPtr = commitPtr->parent;
                }
                cout << "Number of Commits: " << commitCount << endl;

                int fileCount = 0;
                File* filePtr = repo->fileHead;
                while (filePtr)
                {
                    fileCount++;
                    filePtr = filePtr->next;
                }
                cout << "Number of Files: " << fileCount << endl;
                return;
            }
        }
        cout << "Repository not found." << endl;
    }
    else 
    {
        cout << "User not found." << endl;
    }
}
