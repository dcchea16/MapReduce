#include <iostream>
#include <filesystem>
#include "Map.h"
#include "FileManagement.h"

using std::string;
using std::cerr;
using std::cout;
using std::cin;

int main() 
{
    // clear temp dir
	// Replace this with user input
	string tempDirName = ".\\temps";
    FileManagement::deleteDirectoryContents(".\\temps");

    string inputDir = ".\\inputs";

    Map mapper(tempDirName);

	for (const auto& entry : std::filesystem::directory_iterator(inputDir))
	{
		cout << "This is the file i'm reading from: " + entry.path().filename().string() + "\n";
		string contents = FileManagement::readDatafromFile(entry.path().string());
		mapper.map(entry.path().filename().string(), contents);
		// Create a temp file to write to?
	}
}
