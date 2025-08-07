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
void FolderBuilder(map<string, string> folder;, ) {
    if(!is_map_subset(folder, builder.directories)) {
        //we need to check if their is a parent or the parent is the root
        //refactored implementation, do some bug testing and see if this solution works (in my mind it should?)
        string dir;
        if(folder.first == "" || folder.second == "") {
            dir = builder.modDir + "/" + folder.first + folder.second;
        }
        create_directory(dir);
        builder.directories.insert(folder + "/");
    }
}

//search for a folder if not found build use a fileLoad catch to prevent slow i/o
void FileBuilder(path file) {

}

void FileFiller(path file, map<string, string> contents;) {

}
//general use tool to find our direcotry parents and such
//mostly utility for folder/file building
map<string, string> ParentFinder(string searchTerm){
    for (const auto& pair : builder.directories) {
        if(pair.second == searchTerm) {
            map<string, string> parent;
            parent = ParentFinder(parent);
            if(parent == 0) {
                return <parent.first + pair.first, pair.second>;
            }
        }
    }
    return 0;
}
