#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H
#include <string>

using namespace std;

class File
{
public:
    string filename;
    string content;
    File* next;

    File(string name, string data);
};

#endif 
