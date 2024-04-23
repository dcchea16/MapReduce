#include "Map.h"
#include "FileManagement.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <boost/algorithm/string.hpp> 

using std::vector;
using std::string;
using std::unordered_map;



Map::Map(string tempDir) :
    tempDirectory { tempDir }
{
}

void Map::map(const string& key, const string& value)
{
    std::cout << "map \n";

    vector<string> tokens;
    fileName = tempDirectory + "\\" + key;
    int create = FileManagement::createFile(fileName);

    const char* delimeters = "-[]\n\t ,.!?;:&\"'";
    boost::algorithm::split(tokens, value, boost::algorithm::is_any_of(delimeters), boost::algorithm::token_compress_on);

    std::cout << "Exporting file: " + key + '\n';

    for (auto& token : tokens)
    {
        boost::algorithm::to_lower(token);

        if (!token.empty())
        {
            wordCount[token]++;

            bufferCount++; 
            if (bufferCount >= bufferThreshold) 
            {
                exportToFile();
                wordCount.clear();  
                bufferCount = 0;
            }
        }
    }
    flushBuffer();
}

void Map::flushBuffer()
{
    std::cout << "flushBuffer \n";

    if (!wordCount.empty())
    {
        exportToFile();
        wordCount.clear();
        bufferCount = 0;
    }
}

void Map::exportToFile() 
{
    int write = 0;
    for (const auto& wordCountPair : wordCount)
    {
        string wordCombo = "(\"" + wordCountPair.first + "\", " + std::to_string(wordCountPair.second) + ")\n";
        write = FileManagement::writeDataToFile(fileName, wordCombo);
    }
}