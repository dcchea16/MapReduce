#include <iostream>
#include <filesystem>
#include <map>
#include "Map.h"
#include "FileManagement.h"
#include "Reduce.h"
#include "Sort.h"
using std::string;
using std::cerr;
using std::cout;
using std::unordered_map;
using std::map;

int main(int argc, char* argv[])
{
    //inputs
    string inputDir;
    //outputs
    string outputDir;
    //temps
    string tempDir;

    // Convert command-line arguments to appropriate types
    while (FileManagement::readDirectory(inputDir))
    {
        std::cout << "Please type in a valid input directory.\n";
        std::cin >> inputDir;
    }

    while (FileManagement::readDirectory(outputDir))
    {
        std::cout << "Please type in a valid output directory.\n";
        std::cin >> outputDir;
    }

    while (FileManagement::readDirectory(tempDir))
    {
        std::cout << "Please type in a valid temp directory.\n";
        std::cin >> tempDir;
    }

    FileManagement::deleteDirectoryContents(tempDir);

    FileManagement::deleteDirectoryContents(outputDir);

    for (const auto& entry : std::filesystem::directory_iterator(inputDir))
    {
        string fileContent = FileManagement::readDatafromFile(entry.path().string());

        Map mapper(tempDir);
        mapper.map(entry.path().filename().string(), fileContent);
    }

    Sort sorting;

    std::map <std::string, std::vector<int>> words = sorting.create_word_map(tempDir);

    int isSuccessful = 0;
    for (const auto& pair : words) {
        Reduce theReduction(outputDir);
        isSuccessful = isSuccessful + theReduction.reduce(pair.first, pair.second);
    }
    if (isSuccessful == 0) {
        int createOutput = FileManagement::createFile(outputDir + "\\Success.txt");
    }
    //sorting, sorting calls reduce
}