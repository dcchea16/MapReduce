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

Map::Map()
{
}

void Map::map(const string& key, const string& value) 
{
    tokenizeAndCount(value);
}

void Map::exportToFile() 
{
    const string fileName = "temp.txt";
    int create = FileManagement::createFile(".\\temps\\" + fileName);
    int write = 0;
    for (const auto& wordCountPair : wordCountMap)
    {
        write = FileManagement::writeDataToFile(".\\temps\\" + fileName, wordCountPair.first, wordCountPair.second);
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
