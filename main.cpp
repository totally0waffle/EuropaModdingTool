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
		Button("Edit Mod", screen.ExitLoopClosure()),
		newModButton,
	});

	//will be removed for graphical interface
	//terminal gui until release (may be repurposed)

	gameDir = gameDirS;
	screen.Loop(menu);
/*
 *
 * Graveyard ahead, might need later but am too lazy to go back some commits
while(!exists(gameDir)) {
		cout << endl <<"Game directory does not exist";
		cout << "Please enter your game directory: ";
		cin >> gameDir;
		gameDir = gameDirS;
	};

	//sheesh
	//trap the user in a loop till they smarten up or create a new mod directory
	if(!exists(modDir)) {
		while(prompt == '0') {
			if(!exists(modDir)) {
				cout << endl << "Mod directory does not exist" << endl;
				cout << "would you like to create a new mod directory? (0 or 1): ";
				cin.get(prompt);

			};
			if(exists(modDir)) {
				break;
			};
		};
		if(prompt = true) {
			cout << endl << "Please enter the mod name: ";
			getline(cin, name);
			cout << endl << "Please enter the mod version: ";
			getline(cin, version);

			create_directory(modDir);
			GenMod(name, version, modDir, gameDir);
		};
	};
	*/
	while(appFlags.endProgram == 1){};
	return 0;
};

//this can be optimized by a mile but it works
//I would still probably use the built in paradox launcher mod tool to do this
//but you know if I want this to work on a larger scale why not include it
void GenMod(string name, string version, path modDir, path gameDir){
	auto screen = ScreenInteractive::Fullscreen();
	auto menu = Container::Vertical({
		Input(&name, "Enter Mod Name"),
		Input(&version, "Enter Mod Version"),
		Button("Generate .Mod and folder", [&] {
			map<string, string> contents;
			string gameVer;
			gameDir = "/home/waffle/.local/share/Steam/steamapps/common/Europa Universalis IV/";
			//this part I am not proud of, I am basically just grabbing the game version from the provided game directory
			//if this file isnt included then we have a real problem tbh
			string dotModPath = modDir.u8string() += "/descriptor.mod";
			ofstream dotMod(dotModPath);
			string gameVerPath = gameDir.u8string() += "eu4_branch.txt";
			ifstream gameVerFile(gameVerPath);
			//void function so if we can't open the directory just silently kill the function
			if(gameVerFile.is_open() && dotMod.is_open()) {
				gameVerFile >> gameVer;
				gameVer.erase(0, 8);
				gameVer.erase(6, 3);
				gameVer += ".*";
				contents.insert({"version=", version});
				contents.insert({"tags={", "\"Alternative History\" }"}); //im gonna have to update this later tbh
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
