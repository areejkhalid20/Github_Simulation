#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H
#include "RepositoryManagement.h"

void AddFile(Repository* repo, const string& fileName);
void deleteFileFromRepo(Repository* repo, const string& fileName);

#endif