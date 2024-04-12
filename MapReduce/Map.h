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
    unordered_map<string, int> wordCount;
};
