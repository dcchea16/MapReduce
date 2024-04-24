#include "Map.h"
#include "FileManagement.h"

#include <vector>
#include <string>
#include <unordered_map>
#include <boost/algorithm/string.hpp> 

// Processes the input key-value pair to tokenize and count word occurrences
void Map::map(const string& key, const string& value)
{
    std::vector<string> tokens; // Stores the tokens after splitting the value
    fileName = tempDirectory + "\\" + key; // Constructs the file name from the key
    int create = FileManagement::createFile(fileName); // Attempts to create a file for the output

    const char* delimeters = "-[]\n\t ,.!?;:&\"'"; // Delimiters used for splitting the value into tokens
    boost::algorithm::split(tokens, value, boost::algorithm::is_any_of(delimeters), boost::algorithm::token_compress_on); // Splits the value into tokens based on delimiters

    std::cout << "Exporting file: " + key + '\n'; // Logging the export operation

    for (auto& token : tokens)
    {
        boost::algorithm::to_lower(token); // Converts each token to lower case for uniformity

        if (!token.empty()) // Check if the token is non-empty
        {
            wordCount[token]++; // Increment the count for the word

            bufferCount++; // Increment the buffer count
            if (bufferCount >= bufferThreshold) // Check if the buffer threshold is exceeded
            {
                exportToFile(); // Export the current counts to file
                wordCount.clear(); // Clear the word count map
                bufferCount = 0; // Reset the buffer count
            }
        }
    }
    flushBuffer(); // Ensure all remaining data is written to the file
}

// Flushes the remaining word counts to the file if any
void Map::flushBuffer()
{
    if (!wordCount.empty()) // Check if there are any remaining word counts
    {
        exportToFile(); // Export them to the file
        wordCount.clear(); // Clear the word count map
        bufferCount = 0; // Reset the buffer count
    }
}

// Writes the current word counts to the designated file
void Map::exportToFile()
{
    int write = 0;
    for (const auto& wordCountPair : wordCount)
    {
        string wordCombo = "(\"" + wordCountPair.first + "\", " + std::to_string(wordCountPair.second) + ")\n"; // Format each word count as a tuple string
        write = FileManagement::writeDataToFile(fileName, wordCombo); // Write the word count tuple to the file
    }
}
