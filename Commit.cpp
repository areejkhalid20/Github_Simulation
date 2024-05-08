#include "Commit.h"

Commit::Commit(string message, string time, Commit* p)
{
	commitMessage = message;
	timestamp = time;
	parent = p;
	child = NULL;
}
