#include "UserGraph.h"
#include "FileManagement.h"
#include "RepositoryManagement.h"
#include <iostream>
#include <windows.h> 
using namespace std;

//for console manipulation 
void SetConsoleColor(WORD color) 
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleOutput, color);
}

int main()
{
    SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "GitHub Simulation System" << endl;

    UserGraph graph;
    Repository* repoRoot = nullptr;
    Repository* repo;  
    int choice;
    string username, repoName, fileName, commitMsg;
    bool isPublic;
    int userIndex, followingIndex;

    initializeRepo();

    do {
        SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "Menu:" << endl;
        cout << "1. Add User" << endl;
        cout << "2. Follow User" << endl;
        cout << "3. Unfollow User" << endl;
        cout << "4. Create Repository" << endl;
        cout << "5. Delete Repository" << endl;
        cout << "6. Add Commit" << endl;
        cout << "7. Add File to Commit" << endl;
        cout << "8. Delete File from Commit" << endl;
        cout << "9. Display Repositories" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter username: ";
            cin >> username;
            userIndex = graph.addUser(username);
            break;
        case 2:
            cout << "Enter your user index and the index of the user to follow: ";
            cin >> userIndex >> followingIndex;
            graph.follow(userIndex, followingIndex);
            break;
        case 3:
            cout << "Enter your user index and the index of the user to unfollow: ";
            cin >> userIndex >> followingIndex;
            graph.unfollow(userIndex, followingIndex);
            break;
        case 4:
            cout << "Enter repository name and visibility (1 for public, 0 for private): ";
            cin >> repoName >> isPublic;
            repoRoot = CreateRepo(repoRoot, repoName, isPublic);
            break;
        case 5:
            cout << "Enter repository name to delete: ";
            cin >> repoName;
            repoRoot = deleteRepository(repoRoot, repoName);
            break;
        case 6:
            cout << "Enter repository name, commit message, and file name: ";
            cin >> repoName >> commitMsg >> fileName;
            repo = findRepository(repoRoot, repoName);
            if (repo) 
            {
                AddCommit(repo, commitMsg, fileName);
            }
            else 
            {
                cout << "Repository not found" << endl;
            }
            break;
        case 7:
            cout << "Enter repository name and file name to add: ";
            cin >> repoName >> fileName;
            repo = findRepository(repoRoot, repoName);
            if (repo) 
            {
                AddFile(repo, fileName);
            }
            else
            {
                cout << "Repository not found!" << endl;
            }
            break;
        case 8:
            cout << "Enter repository name and file name to delete: ";
            cin >> repoName >> fileName;
            repo = findRepository(repoRoot, repoName);
            if (repo) 
            {
                deleteFileFromRepo(repo, fileName);  
            }
            else
            {
                cout << "Repository not found." << endl;
            }
            break;
        case 9:
            displayRepositories(repoRoot);
            break;
        case 10:
            cout << "Exiting system." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 10);

    SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
