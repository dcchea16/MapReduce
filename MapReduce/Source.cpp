#include <iostream>
#include <filesystem>
#include "Map.h"
#include "FileManagement.h"

using std::string;
using std::cerr;
using std::cout;

int main() 
{
    // clear temp dir
    FileManagement::deleteDirectoryContents(".\\temps");

    string inputDir = ".\\inputs";

    Map mapper;

	for (const auto& entry : std::filesystem::directory_iterator(inputDir))
	{
		string contents = FileManagement::readDatafromFile(entry.path().string());
		mapper.map(entry.path().string(), contents);
		// Create a temp file to write to?
	}
}
