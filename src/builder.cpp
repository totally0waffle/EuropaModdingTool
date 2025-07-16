//Simply a library script to reduce code repeats
//anything related to building or input(tbd #might move to dedicated input/output library)
//might let me refactor some of the main file and condense it into a smaller package
#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>

#include "builder.h"

using namespace std;
using namespace std::filesystem;
//construct all of our folders
//plans are to remove empty on save & quit
void FolderBuilder() {

}

//search for a folder if not found build use a fileLoad catch to prevent slow i/o
void FileBuilder(path file) {

}

void FileFiller(path file, map<string, string> contents;) {

}
