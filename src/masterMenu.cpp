#include <filesystem>
#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component_options.hpp>
#include "flags.h"

//hold our flags for when we need to exit
Flags appFlags;
using namespace std;
using namespace std::filesystem;
using namespace ftxui;

void master(path modDir, path gameDir) {
    //Here we sould pre-load all of our mod folder contents into variables so we can modify them later
};
