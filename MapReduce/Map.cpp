#include "Map.h"
#include "FileManagement.h"

#include <vector>
#include <string>
#include <unordered_map>
#include <boost/algorithm/string.hpp> 

// Processes the input key-value pair to tokenize and count word occurrences
void Map::map(const string& key, const string& value)
{
    // Stores the tokens after splitting the value
    std::vector<string> tokens;
    // Constructs the file name from the key
    fileName = tempDirectory + "\\" + key;
    // Attempts to create a file for the output
    FileManagement::createFile(fileName);

    // Delimiters used for splitting the value into tokens
    const char* delimeters = "-[]\n\t ,.!?;:&\"'";
    // Splits the value into tokens based on delimiters
    boost::algorithm::split(tokens, value, boost::algorithm::is_any_of(delimeters), boost::algorithm::token_compress_on);
    // Logging the export operation
    std::cout << "Exporting file: " + key + '\n';

    // Iterate through all the tokenized strings
    for (auto& token : tokens)
    {
        // Converts each token to lower case for uniformity
        boost::algorithm::to_lower(token);

        // Check if the token is non-empty
        if (!token.empty())
        {
            // Increment the count for the word
            wordCount[token]++;

            // Increment the buffer count
            bufferCount++;
            // Check if the buffer threshold is exceeded
            if (bufferCount >= bufferThreshold)
            {
                // Export the current counts to file
                exportToFile();
                // Clear the word count map
                wordCount.clear();
                // Reset the buffer count
                bufferCount = 0;
            }
        }
    }
    // Ensure all remaining data is written to the file
    flushBuffer();
}

// Flushes the remaining word counts to the file if any
void Map::flushBuffer()
{
    // Check if there are any remaining word counts
    if (!wordCount.empty())
    {
        // Export them to the file
        exportToFile();
        // Clear the word count map
        wordCount.clear();
        // Reset the buffer count
        bufferCount = 0;
    }
}

// Writes the current word counts to the designated file
void Map::exportToFile()
{
    // Iterate through all the word count pairs
    for (const auto& wordCountPair : wordCount)
    {
        // Format each word count as a tuple string
        string wordCombo = "(\"" + wordCountPair.first + "\", " + std::to_string(wordCountPair.second) + ")\n";
        // Write the word count tuple to the file
        FileManagement::writeDataToFile(fileName, wordCombo);
    }
}
