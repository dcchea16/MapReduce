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

    string fileContent = FileManagement::readDatafromFile(inputFilePath);
    if (fileContent.empty()) 
    {
        cerr << "Input file is empty or could not be read.\n";
        return 1;
    }

    Map mapper(inputBaseName, tempDir);
    mapper.map(inputBaseName, fileContent);
    mapper.exportToFile();

    cout << "Mapping completed. Check the temp directory for output.\n";
}
