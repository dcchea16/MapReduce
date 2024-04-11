#include <iostream>
#include "Map.h"
#include "FileManagement.h"

using std::string;
using std::cerr;
using std::cout;

int main() 
{
    string inputDir = ".\\inputs";
    string tempDir = ".\\temps";
    string inputBaseName = "input1"; // Only the base name, no path, no extension

    string inputFilePath = inputDir + "\\" + inputBaseName + ".txt";

	std::string foobar = FileManagement::readDatafromFile(".\\inputs\\input1.txt");

	std::cout << "foobar: " << foobar << '\n';

    cout << "Mapping completed. Check the temp directory for output.\n";
}
