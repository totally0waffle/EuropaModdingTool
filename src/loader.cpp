#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>
#include <map>

#include "builder.h"

using namespace std;
using namespace std::filesystem;

Builder builder;
Flags appFlags;

void preload() {
    /*
    bro I know this will get coded while high, just follow the list man try and implement it how either of us normally would (its a puzzle ffs) ~sober Waffle
    
    here we can abuse our builder script to preload everything. its a void statement so just call it timeout and continue execution
    lets run through this step by step:
    1. check the status of the mod folder, under the scenario it doesnt exist throw an exception (we can either solve this by making a new folder or reverting back to mod generator
    2. copy the structure from eu4 over to the mod folder, we will use a cleaner afterwards to remove the fluff (we just want everything to be ready to be made
    this will include things like our common folder and its sub folders, history, localization and the such
    empty directories are fine but we do not need to create empty files for clarity sake.
    3. index directory pathing for easier usage and navigation later
    4. index current files to their parent folders and treat it like a linked list to find full pathing
    5. Possibly validate our .mod file and offer an update?
    6. (optional) index all of our variables, scopes and tags for quicker reading and writing (this will all be stored within a .json for better organization and modification later 
    but how I see it, all of these should be stored within a list because we dont want to rely on text file reading each time as that could long and annoying... we also shouldnt have to worry
    about overflow for this case atleast, this also leaves us open with the possibility of implementing support for games like hoi or victoria (any other clausewitz game I hope) 
    */
    
}

void finder(path master) {
    try {
        for(const auto& entry : directory_iterator(master)) {
            if(is_directory(entry.status())) {
                gameDirectories.insert(master, entry);
                finder(entry.path());
            }
        }
    }
}
