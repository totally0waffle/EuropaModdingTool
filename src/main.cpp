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

Flags appFlags;
//I should remove these, but at this point im too high to care really
using namespace std;
using namespace std::filesystem;
using namespace ftxui;

//I'm probably going to need these in every script so make it readable everywhere


void GenMod(string name, string version, path modDir, path gameDir);

int main() {
	//really all main is gonna be used for is building the directory variables and storage
	//interface script should be seperate
	path gameDir, modDir;
	string name, version, gameDirS, modDirS;
	pair <string,string> files, dirs;
	auto screen = ScreenInteractive::Fullscreen();
	auto newModButton = Button("Make new Mod", [&] {
		modDir = "./" + modDirS;
		create_directory(modDir);
		GenMod("", "", modDir, gameDir);
		screen.ExitLoopClosure();
	});
	auto menu = Container::Vertical({
		Input(&gameDirS, "Enter Game Directory"),
		Input(&modDirS, "Enter Mod Directory"),
		Button("Edit Mod", [&]{
				gameDir = gameDirS;
				if(!exists (gameDir)){
					cout << "Game directory does not exist";
				};
				if(exists (gameDirS)) {

					screen.Exit();
				}
		}),
		newModButton,
	});

	//will be removed for graphical interface
	//terminal gui until release (may be repurposed)

	gameDir = gameDirS;
	screen.Loop(menu);
	while(appFlags.endProgram == 1){};
	return 0;
};

//this can be optimized by a mile but it works
//I would still probably use the built in paradox launcher mod tool to do this
//but you know if I want this to work on a larger scale why not include it
void GenMod(string name, string version, path modDir, path gameDir){
	string gameVer, tags;
	gameDir = "/home/waffle/.local/share/Steam/steamapps/common/Europa Universalis IV/";
	//this part I am not proud of, I am basically just grabbing the game version from the provided game directory
	//if this file isnt included then we have a real problem tbh
	string gameVerPath = gameDir.u8string() += "eu4_branch.txt";
	ifstream gameVerFile(gameVerPath);
	gameVerFile >> gameVer;
	gameVer.erase(0, 8);
	gameVer.erase(6, 3);
	gameVer += ".*";
	auto screen = ScreenInteractive::Fullscreen();
	auto menu = Container::Vertical({
		Input(&name, "Enter Mod Name"),
		Input(&version, "Enter Mod Version"),
		Input(&gameVer, "Enter Game Version"),
		Input(&tags, "Enter Mod Tags (each tag sperated by quotes)"), //Im gonna have to make a much better solution lol
		Button("Generate .Mod and folder", [&] {
			map<string, string> contents;
			//void function so if we can't open the directory just silently kill the function
			string dotModPath = modDir.u8string() += "/descriptor.mod";
			ofstream dotMod(dotModPath);
			if(gameVerFile.is_open() && dotMod.is_open()) {
				contents.insert({"version=", version});
				contents.insert({"tags={", tags + "}"}); //im gonna have to update this later tbh
				contents.insert({"name=", name});
				contents.insert({"supported_version=", gameVer});
				for (const auto& pair : contents) {
					dotMod << pair.first << pair.second << endl;
				};
				dotMod.close();
				gameVerFile.close();
			};
			appFlags.endProgram = true;
			screen.Exit();
		}),
	});
	screen.Loop(menu);
};
