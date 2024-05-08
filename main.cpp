#include <iostream>
#include <windows.h>  
#include <cstdlib>    
#include "GitHubSimulation.h"
using namespace std;

int main() 
{
    GitHubSimulation gitHubSim;
    bool isLoggedIn = false;
    string username, password;
    int choice;

    //set background to purple and text to black
    system("Color 50");

    while (true) 
    {
        system("cls");  
        if (!isLoggedIn) 
        {
            cout << "1. Register User\n2. Login\nChoose option: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                gitHubSim.registerUser(username, password);
                break;
            case 2:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                isLoggedIn = gitHubSim.login(username, password);
                break;
            default:
                cout << "Invalid choice. Please choose again.\n";
            }
        }
        else 
        {
            cout << "3. Logout\n4. View Profile\n5. Create Repository\n6. Add Commit to Repository\n7. Add File to Repository\n8. Delete Repository\n9. Fork Repository\n10. Make Repository Public\n11. Make Repository Private\n12. View Repository Stats\n13. Exit\nChoose option: ";
            cin >> choice;

            switch (choice) 
            {
            case 3:
                gitHubSim.logout();
                isLoggedIn = false;
                break;
            case 4:
                gitHubSim.viewProfile(username);
                break;
            case 5:
                gitHubSim.createRepository(username);
                break;
            case 6:
                gitHubSim.addCommitToRepository(username);
                break;
            case 7:
                gitHubSim.addFileToRepository(username);
                break;
            case 8:
                gitHubSim.deleteRepository(username);
                break;
            case 9:
                gitHubSim.forkRepository(username);
                break;
            case 10:
                gitHubSim.makeRepositoryPublic(username);
                break;
            case 11:
                gitHubSim.makeRepositoryPrivate(username);
                break;
            case 12:
                gitHubSim.viewRepositoryStats(username);
                break;
            case 13:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please choose again.\n";
            }
        }
    }

    return 0;
}
