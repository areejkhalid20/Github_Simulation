#include "Utilities.h"
using namespace std;

//hash function to calculate the hash value
int hashFunc(const string& key)
{
	int hash_val = 0;
	for (char c : key)
	{
		hash_val = (hash_val * 31 + c) % TABLE_SIZE; //calculate the respective hash value 
	}
	return hash_val;
}
