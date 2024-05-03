#include<iostream>
#include"UserManagement.h"
#include "Utilities.h"

using namespace std;

//creating a structure to store user name and password
struct User
{
	string username, password;
	bool isActive;

	User()
	{
		isActive = false;
	}
};

User table[TABLE_SIZE];

//this function is used to initialize the table 
void initUserTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		table[i].isActive = false; //initially make them non active users 
	}
}

//this function will be used to register a user 
bool RegisterUser(const string& username, const string& password)
{
	int i = hashFunc(username); //this will calculate the index using hash function 
	int original_index = i;

	while (table[i].isActive)
	{
		if (table[i].username == username)
		{
			cout << "Username already exists" << endl;
			return false;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == original_index)
		{
			cout << "Hash table full" << endl;
			return false;
		}
	}
	//it means registration is successful
	table[i].username = username;
	table[i].password = password;
	table[i].isActive = true;

	cout << "Successfully registered" << endl;
	return true;
}

//this function will be used to login a user to its account 
bool LoginUser(const string& username, const string& password)
{
	int i = hashFunc(username);
	//compare the username and password to authorize the user 
	while(table[i].isActive) 
	{
		if (table[i].username == username && table[i].password == password)
		{ 
			cout << "Login successful" << endl;
			return true;
		}
		i = (i + 1) % TABLE_SIZE;
		if (!table[i].isActive)
		{
			break; //this will stop if an inactive cell is found
		}
	}
	cout << "Incorrect username or password" << endl;
	return false;
}

void ViewProfile(const string& username)
{
	int i = hashFunc(username);
	//compare the username to find the user 
	while (table[i].isActive)
	{
		if (table[i].username == username)
		{
			cout << "Username: " << table[i].username << endl;
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		//this will break if an inactive cell is found 
		if (!table[i].isActive)
		{
			break;
		}
	}
	cout << "Profile not found" << endl;
}


