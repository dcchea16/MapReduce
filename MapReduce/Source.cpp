#include <iostream>
#include <filesystem>
#include <map>
#include "Map.h"
#include "FileManagement.h"
#include "Reduce.h"

using std::string;
using std::cerr;
using std::cout;
using std::unordered_map;
using std::map;

int main(int argc, char* argv[])
{
    //checks if there are the correct number of inputs
    if (argc < 4) {
        cerr << "Error: Not enough inputs. \n";
        return 1; // Return error code
    }
    else if (argc > 4) {
        cerr << "Error: Too many inputs. \n";
        return 1; // Return error code
    }

    // Convert command-line arguments to appropriate types
    string inputDir = argv[1];
    string tempDir = argv[2];
    string outputDir = argv[3];

    if (!std::filesystem::exists(inputDir))
    {
        std::cerr << "error directory path (" << inputDir << ") doesn't exist!\n";
        return 1;
    }

    if (std::filesystem::is_empty(inputDir))
    {
        std::cerr << "directory path (" << inputDir << ") is empty!\n";
        return 1;
    }

    for (const auto& entry : std::filesystem::directory_iterator(inputDir))
    {
        string fileContent = FileManagement::readDatafromFile(entry.path().filename().string());
        if (fileContent.empty())
        {
            cerr << entry.path().string()<<" is empty or could not be read.\n";
        }
        else
        {
            Map mapper(tempDir);
            mapper.map(entry.path().filename().string(), fileContent);
        }
    }

    std::map <std::string, std::vector<int>> words = sorting.create_word_map(tempDir);
    int isSuccessful = 0;
    for (const auto& pair : words) {
        Reduce theReduction(outputDir);
        isSuccessful = isSuccessful + theReduction.reduce(pair.first, pair.second);
    }
    if (isSuccessful == 0) {
        int createOutput = FileManagement::createFile(outputDir + "\Success.txt");
    }
    //sorting, sorting calls reduce
}