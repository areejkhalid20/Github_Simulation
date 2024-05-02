//this is the main function basically serving as the entry point for the code 
#include "UserManagement.h"
using namespace std;

int main()
{
	initUserTable(); 
	RegisterUser("Areej_Khalid","123re");
	LoginUser("Areej_Khalid","123re");
	ViewProfile("Areej_Khalid");
}