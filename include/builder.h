//TODO this is gonna contain our global paths from here on out e.g. gamepath & modpath
//also implement directory list for both EU4 and the Mod folder without files
//create a linked list with mod directory to store created files
//(simply directory navigation implementation phase)
#ifndef BUILDER_H
#define BUILDER_H
#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
using namespace std::filesystem;
class Builder {
public:
    path gameDir;
    path modDir;
    map<string, string> directories;
    void FolderBuilder(string folder);
    void FileBuilder(path file);
    void FileFiller(path file, map<string, string> contents);
};

extern Builder builder;

#endif
