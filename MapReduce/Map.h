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

// Class to handle mapping and counting of words from text data
class Map
{
public:
    // Constructor to initialize the Map with a directory for temporary storage
    Map(string tempDir) :  tempDirectory(tempDir) {}  // Initializes the tempDirectory member with the provided directory path

    // Process a key-value pair by tokenizing and counting words
    void map(const string& key, const string& value);

    // Export the current word counts to a file
    void exportToFile();

private:
    unordered_map<string, int> wordCount; // Hash table to store word counts
    void flushBuffer(); // Flush remaining words from buffer to file
    int bufferCount = 0; // Buffer Tracker
    const int bufferThreshold = 100; // Threshold for the buffer
    string fileName; // Name of the temp file where word counts are stored

    const string tempDirectory; // Directory path for storing temp files
};
