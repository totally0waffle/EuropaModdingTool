#include <filesystem>
#include <string>
#include <regex>
#include <iostream>
#include <fstream>

//I should remove these, but at this point im too high to care really
using namespace std;
using namespace std::filesystem;

int main() {
	//really all main is gonna be used for is building the directory variables and storage
	//interface script should be seperate
	bool prompt; //this is ugly :(
	path gameDir, modDir;
	string name, version;
	pair <string,string> files, dirs;

	//will be removed for graphical interface
	//terminal gui until release (may be repurposed)
	cout << "Please enter your game directory: ";
	cin >> gameDir;
	cout << endl <<"Please enter your mod directory: ";
	cin >> modDir;

	while(!exists(gameDir)) {
		cout << endl <<"Game directory does not exist";
		cout << "Please enter your game directory: ";
		cin >> gameDir;
	}
	//sheesh
	//trap the user in a loop till they smarten up or create a new mod directory
	if(!exists(modDir)) {
		while(prompt = false) {
			if(!exists(modDir)) {
				cout << endl << "Mod directory does not exist";
				cout << "would you like to create a new mod directory? (0 or 1): ";
				cin >> prompt;
			if(exists(modDir)) {
				break;
			}
		}
		if(prompt = true) {
			cout << endl << "Please enter the mod name: ";
			cin >> name;
			cout << endl << "Please enter the mod name: ";
			cin >> version;
			create_directory(modDir);
			GenMod(name, version, modDir, gameDir);
		}
	}
}

//this can be optimized by a mile but it works
//I would still probably use the built in paradox launcher mod tool to do this
//but you know if I want this to work on a larger scale why not include it
void GenMod(string name, string version, path modDir, path gameDir){
	map<string, string> contents;
	string gameVer;
	//this part I am not proud of, I am basically just grabbing the game version from the provided game directory
	//if this file isnt included then we have a real problem tbh
	string dotModPath = modDir.u8string() += "descriptor.mod";
	ofstream dotMod(dotModPath)
	string gameVerPath = gameDir.u8string() += "eu4_branch.txt";
	ifstream gameVerFile(gameVerPath);
	//void function so if we can't open the directory just silently kill the function
	if(gameVerFile.is_open() && dotMod.is_open()) {
		gameVerFile >> gameVer;
		gameVer.erase(0, 8);
		gameVer.erase(6, 3);
		gameVer += "*";
		contents.insert({"version=", version});
		contents.insert({"tags={", "\"Alternative History\" }"}); //im gonna have to update this later tbh
		contents.insert({"name=", name});
		contents.insert({"supported_version=", gameVer});
		for (const auto& pair : contents) {
			dotMod >> pair.first >> pair.second >> endl;
		}
		dotMod.close();
		gameVerFile.close();
	}
}
