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
	// Replace temporary directory with user input
	string tempDirName = ".\\temps";

	// Clear temp directory
    FileManagement::deleteDirectoryContents(tempDirName);

	// Replace input directory with user input
    string inputDir = ".\\inputs";

	// Create Map object with temporary directory name
    Map mapper(tempDirName);

	// Iterate through all of the files in the input directory
	for (const auto& entry : std::filesystem::directory_iterator(inputDir))
	{
		// Read all files from the input directory
		string contents = FileManagement::readDatafromFile(entry.path().string());

		// Pass in the file name and its contents
		mapper.map(entry.path().filename().string(), contents);
	}
}
