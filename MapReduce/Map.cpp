#include "Map.h"
#include "FileManagement.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <boost/algorithm/string.hpp> 

using std::vector;
using std::string;
using std::unordered_map;

Map::Map()
{

}

void Map::map(const string& key, const string& value) 
{
    vector<string> tokens;
    boost::algorithm::split(tokens, value, boost::algorithm::is_any_of("\t ,.!?;:\"'"), boost::algorithm::token_compress_on);

    for (auto& token : tokens)
    {
        boost::algorithm::to_lower(token);

        if (!token.empty())
        {
            wordCount[token]++;
        }
    }
    exportToFile();
}

void Map::exportToFile() 
{
    const string fileName = "temp.txt";
    int create = FileManagement::createFile(".\\temps\\" + fileName);
    int write = 0;
    for (const auto& wordCountPair : wordCount)
    {
        write = FileManagement::writeDataToFile(".\\temps\\" + fileName, wordCountPair.first, wordCountPair.second);
    }
}