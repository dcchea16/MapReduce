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

    //create a Sort class
    Sort sorting;
    //calls the create_word_map function, which goes through the temp directory and returns a map with all the words in the temp directory files and a vector of of the numbers associated with the word
    std::map <std::string, std::vector<int>> words = sorting.create_word_map(tempDir);

    //creates a varible to determine if all of the words have been added to the file correctly, if they have it will remain 0
    int isSuccessful = 0;
    
    //loop to run through the string vector pairs in the map and use a reduce class to add the word and the vector sum to an output file in the output directory
    for (const auto& pair : words) {
        //creates a Reduce class that saves the output directory
        Reduce theReduction(outputDir);
        
        //calls the reduce function that adds together the vector to create a vector sum and outputs the key and the sum to a file in the output directory
        //reduce function returns 0 if it is successful at adding it and returns 1 if unsuccessful, that number is added to isSuccessful
        isSuccessful = isSuccessful + theReduction.reduce(pair.first, pair.second);
    }

    //if the previous loop was able to add all of the key, sum pairs to the file an success file is created in the output directory
    if (isSuccessful == 0) {
        int createOutput = FileManagement::createFile(outputDir + "\\Success.txt");
    }
    
}
