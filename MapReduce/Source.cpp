#include "Map.h"
#include "FileManagement.h"
#include "Reduce.h"
#include "Sort.h"

#include <iostream>
#include <filesystem>

int main(int argc, char* argv[])
{
    // For this program, the input directory name is "inputs"
    string inputDir;
    // For this program, the input directory name is "outputs"
    string outputDir;
    // For this program, the input directory name is "temps"
    string tempDir;

    // Convert command-line arguments to appropriate types
    // Prompt user for input directory
    while (FileManagement::readDirectory(inputDir))
    {
        std::cout << "Please type in a valid input directory.\n";
        std::cin >> inputDir;
    }

    // Prompt user for output directory
    while (FileManagement::readDirectory(outputDir))
    {
        std::cout << "Please type in a valid output directory.\n";
        std::cin >> outputDir;
    }

    // Prompt user for temporary directory
    while (FileManagement::readDirectory(tempDir))
    {
        std::cout << "Please type in a valid temp directory.\n";
        std::cin >> tempDir;
    }

    // If the instance of the program has already been used, ensure that the temporary directory is empty
    FileManagement::deleteDirectoryContents(tempDir);
    // If the instance of the program has already been used, ensure that the output directory is empty
    FileManagement::deleteDirectoryContents(outputDir);

    // Create a map class, taking in the temporary directory as a parameter
    Map mapper(tempDir);

    // Iterate through the input files in the input directory
    for (const auto& entry : std::filesystem::directory_iterator(inputDir))
    {
        // Read each file and output its contents
        string fileContent = FileManagement::readDatafromFile(entry.path().string());

        // Use the map function to pass in the file name and the file contents
        mapper.map(entry.path().filename().string(), fileContent);
    }

    // Create a Sort class
    Sort sorting;

    // Call the create_word_map function, which goes through the temp directory and returns a map
    // with all the words in the temp directory files and a vector of of the numbers associated with the word
    std::map <std::string, std::vector<int>> words = sorting.create_word_map(tempDir);

    // Create a varible to determine if all of the words have been added to the file correctly,
    // if they have it will remain 0
    int isSuccessful = 0;

    // Creates a Reduce class that saves the output directory
    Reduce theReduction(outputDir);

    //loop to run through the string vector pairs in the map and use a reduce class
    // to add the word and the vector sum to an output file in the output directory
    for (const auto& pair : words)
    {
        // Call the reduce function that adds together the vector to create a vector sum
        // and outputs the key and the sum to a file in the output directory
        // Reduce function returns 0 if it is successful at adding it and returns 1 if unsuccessful,
        // that number is added to isSuccessful
        isSuccessful = isSuccessful + theReduction.reduce(pair.first, pair.second);
    }

    // If the previous loop was able to add all of the key, sum pairs to the file
    // an success file is created in the output directory
    if (isSuccessful == 0) {
        int createOutput = FileManagement::createFile(outputDir + "\\Success.txt");
    }
}
