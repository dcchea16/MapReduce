#pragma once

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Map 
{
public:
    Map();
    Map(string tempDir);
    void map(const string& key, const string& value);
    void exportToFile();

private:
    unordered_map<string, int> wordCount;
    void flushBuffer();
    int bufferCount = 0;
    const int bufferThreshold = 100;
    string fileName;

    const string tempDirectory;
};
