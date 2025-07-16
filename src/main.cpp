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
#include "builder.h"

Flags appFlags;
Builder builder;
//I should remove these, but at this point im too high to care really
// I love namespaces :-D
using namespace std;
using namespace std::filesystem;
using namespace ftxui;

void GenMod();

int main() {
	//really all main is gonna be used for is our initial loading phase
	//I am actually happy with this now I think
	string gameDirS, modDirS;
	auto screen = ScreenInteractive::Fullscreen();
	auto newModButton = Button("Make new Mod", [&] {
		builder.modDir = "./" + modDirS;
		//use the old method here, preloading will use the new method
		create_directory(builder.modDir);
		GenMod();
		screen.ExitLoopClosure();
	});
	auto menu = Container::Vertical({
		Input(&gameDirS, "Enter Game Directory"),
		Input(&modDirS, "Enter Mod Directory"),
		Button("Edit Mod", [&]{
				builder.gameDir = gameDirS;
				if(!exists (builder.gameDir)){
					cout << "Game directory does not exist";
				};
				if(exists (builder.gameDir)) {
					screen.Exit();
				}
		}),
		newModButton,
	});
	builder.gameDir = gameDirS;
	screen.Loop(menu);
	while(appFlags.endProgram == false){};
	return 0;
};

//this can be optimized by a mile but it works
//This lets you input custom tags atleast which are kinda cool, but try and stick to default tags
//but you know if I want this to work on a larger scale why not include it
void GenMod(){
	string gameVer, tags, name, version;
	builder.gameDir = "/home/waffle/.local/share/Steam/steamapps/common/Europa Universalis IV/";
	string gameVerPath = builder.gameDir.u8string() += "eu4_branch.txt";
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
		//TODO find a better fucking solution :(
		//{dropdown of defaults??? idk how to do that yet}
		Input(&tags, "Enter Mod Tags (each tag sperated by quotes)"), //Im gonna have to make a much better solution lol
		Button("Generate .Mod and folder", [&] {
			map<string, string> contents;
			//void function so if we can't open the directory just silently kill the function
			string dotModPath = builder.modDir.u8string() += "/descriptor.mod";
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
