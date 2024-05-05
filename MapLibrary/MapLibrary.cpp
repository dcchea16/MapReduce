#include "pch.h"  
#include <utility>
#include <limits.h>
#include "MapLibrary.h"
#include <filesystem>
#include "FileManagementLibrary.h"
#include <boost/algorithm/string.hpp> 
#include <iostream>
#include <windows.h>

typedef double (*funcCreateFile)(const string&);
typedef double (*funcWriteToFile)(const string&, const string&);
// Constructor for Map class
Map::Map() : fileName(""), bufferCount(0), bufferThreshold(100) {
    wordCount.clear();
}

//// Function to create a Map instance, exported as C function
//extern "C" MAPLIBRARY_API Map * Map_Create() {
//    return new Map();
//}
//
//// Function to destroy a Map instance, exported as C function
//extern "C" MAPLIBRARY_API void Map_Destroy(Map * map) {
//    delete map;
//}
//
//// Processes the input key-value pair to tokenize and count word occurrences, exported as C function
//extern "C" MAPLIBRARY_API void Map_Map(Map * map, const char* key, const char* value) {
//    if (map != nullptr && key != nullptr && value != nullptr) {
//        map->map(std::string(key), std::string(value));
//    }
//}
//
//// Flushes the remaining word counts to the file if any, exported as C function
//extern "C" MAPLIBRARY_API void Map_FlushBuffer(Map * map) {
//    if (map != nullptr) {
//        map->flushBuffer();
//    }
//}
//
//extern "C" MAPLIBRARY_API void Map_Test()
//{
//    std::cout << "help me";
//}

// Internal C++ method implementations
void Map::map(const std::string& key, const std::string& value) 
{
    std::vector<std::string> tokens;
    HINSTANCE hDLL;
    funcCreateFile createFile;
    funcWriteToFile writeDataToFile;
    const wchar_t* libName = L"FileManagementLibrary";
    hDLL = LoadLibraryEx(libName, NULL, NULL); // Handle to DLL
    if (hDLL != NULL) {
        createFile = (funcCreateFile)GetProcAddress(hDLL, "createFile");
        writeDataToFile = (funcWriteToFile)GetProcAddress(hDLL, "writeDataToFile");
        // Create the file name using the directory path and the name of the file
        string outputFileName = fileName + "\\" + key;

        // If the file exists don't need to do anything
        if (std::filesystem::exists(outputFileName))
        {
        }
        // If the file doesn't exist, create it
        else
        {
            if (createFile != NULL) {
                createFile(outputFileName);
            }
        }

        const char* delimiters = "-[]\n\t ,.!?;:&\"'";
        boost::algorithm::split(tokens, value, boost::algorithm::is_any_of(delimiters), boost::algorithm::token_compress_on);

        for (auto& token : tokens) {
            boost::algorithm::to_lower(token);
            if (!token.empty()) {
                wordCount[token]++;
                bufferCount++;
                if (bufferCount >= bufferThreshold) {
                    exportToFile();
                    wordCount.clear();
                    bufferCount = 0;
                }
            }
        }
        // Returns the result of the FileManagement function
        FreeLibrary(hDLL);
    }
    else {
        std::cerr << "Library load failed!" << std::endl;
    }
}

void Map::flushBuffer() {
    if (!wordCount.empty()) {
        exportToFile();
        wordCount.clear();
        bufferCount = 0;
    }
}

void Map::map_test()
{
    std::cout << "help";
}

void Map::exportToFile() {
    HINSTANCE hDLL;
    funcCreateFile createFile;
    funcWriteToFile writeDataToFile;
    const wchar_t* libName = L"FileManagementLibrary";
    hDLL = LoadLibraryEx(libName, NULL, NULL); // Handle to DLL
    if (hDLL != NULL) {
        writeDataToFile = (funcWriteToFile)GetProcAddress(hDLL, "writeDataToFile");

        for (const auto& wordCountPair : wordCount) 
        {
            std::string wordCombo = "(\"" + wordCountPair.first + "\", " + std::to_string(wordCountPair.second) + ")\n";
            writeDataToFile(fileName, wordCombo);
        }

        // Returns the result of the FileManagement function
        FreeLibrary(hDLL);
    }
    else {
        std::cout << "Library load failed!" << std::endl;
    }
}