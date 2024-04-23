/*
This is the header file for the Map class. This will contain all of the function declarations
for the program and its private members. The map class will contain a public method map(), that accepts a key and value.
The key will be the file name and the value will be a single line of raw data from the file.
The map() function will tokenize the value into distinct words (remove punctuation, whitespace and capitalization).
The map() function will call a second function export() that takes a key and value as two parameters.
The export function will buffer output in memory and periodically write the data out to disk (periodicity can be based on the size of the buffer).
The intermediate data will be written to the temporary directory (specified via command line). 
*/
#pragma once

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Map 
{
public:
    Map(string tempDir) :
        tempDirectory(tempDir) {}
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
