#include "Map.h"
#include "FileManagement.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <fstream>

using std::string;
using std::istringstream;
using std::ofstream;
using std::cerr;
using std::transform;
using std::remove_if;

Map::Map(const string& inputFileName, const string& tempDirectory): tempDirectory(tempDirectory) 
{
    // Construct the temporary file name
    size_t lastdot = inputFileName.find_last_of(".");
    string basename = (lastdot == string::npos) ? inputFileName : inputFileName.substr(0, lastdot);
    tempFileName = tempDirectory + "\\temp" + basename + ".txt";
}

void Map::map(const string& key, const string& value) 
{
    tokenizeAndCount(value);
}

void Map::exportToFile() 
{
    ofstream tempFile(tempFileName);
    if (!tempFile.is_open()) 
    {
        cerr << "Failed to open temp file for writing: " << tempFileName << '\n';
        return;
    }

    for (const auto& wordCountPair : wordCountMap) 
    {
        tempFile << wordCountPair.first << " " << wordCountPair.second << "\n";
    }
}

void Map::tokenizeAndCount(const string& line) 
{
    istringstream stream(line);
    string token;

    while (stream >> token) 
    {
        token.erase(remove_if(token.begin(), token.end(), [](char ch) { return ispunct(ch); }), token.end());
        transform(token.begin(), token.end(), token.begin(), ::tolower);

        if (!token.empty()) 
        {
            wordCountMap[token]++;
        }
    }
}
