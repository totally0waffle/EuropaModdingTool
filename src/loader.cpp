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
