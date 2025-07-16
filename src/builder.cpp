//Simply a library script to reduce code repeats
//anything related to building or input(tbd #might move to dedicated input/output library)
//might let me refactor some of the main file and condense it into a smaller package
#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>
#include <map>

#include "builder.h"

using namespace std;
using namespace std::filesystem;

Builder builder;
//construct all of our folders
//plans are to remove empty on save & quit
//first position will be the parent second will be the child directory
void FolderBuilder(map<string, string> folder;) {
    if(!is_map_subset(folder, builder.directories)) {
        create_directory(builder.modDir + "/" + parent + folder);
        builder.directories.insert(folder);
    }
}

//search for a folder if not found build use a fileLoad catch to prevent slow i/o
void FileBuilder(path file) {

}

void FileFiller(path file, map<string, string> contents;) {

}
