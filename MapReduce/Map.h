#pragma once

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Map 
{
public:
    Map();
    void map(const string& key, const string& value);
    void exportToFile();

private:
    string tempDirectory;
    string tempFileName;
    unordered_map<string, int> wordCountMap;

    void tokenizeAndCount(const string& line);
};
