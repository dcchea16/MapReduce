#include "Sort.h"
#include "FileManagement.h"

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

std::map <std::string, std::vector<int>>  Sort::create_word_map(string tempDir)
{
    // Get one file for all tuples in the temporary directory
    FileManagement::readAllDirectoryFileContents(tempDir);
    // Create a variable that will be used as the input file
    std::ifstream input_file(tempDir + "\\allWords.txt");

    // Create a variable that will be used to look at the current line
    string line;
    // Create a variable that will be used as the current part being examined
    // when line is divided into two parts at the comma
    string part;
    // Create a variable that will store a word without any symbols
    string strNew;
    // Create a variable that will hold the value in the tuple without any symbols
    int value;
    // Create variable that will be used to loop through parts
    int count = 0;

    // Create a map of strings and integers that will hold the words and their respective values
    std::map< std::string, std::vector<int>> words;

    // Get line in file
    while (getline(input_file, line))
    {
        std::istringstream is(line);

        // Separate word from integer/count
        while (getline(is, part, ','))
        {
            // If first loop, remove quotation
            if (count == 0) {
                unsigned first = part.find("\"");
                unsigned last = part.find_last_of("\"");
                strNew = part.substr(first, last - first);
                if (strNew.front() == '"') {
                    strNew.erase(0, 1); // erase the first quotation
                }
            }
            // If second iteration, remove parenthesis, get integer value and add word and count to map
            else if (count == 1)
            {
                if (part.back() == ')')
                {
                    // Get rid of the closing parenthesis
                    part.erase(part.size() - 1);
                }
                // Convert to int
                value = stoi(part);

                // Since word and int are acquired, store in map
                if (words.find(strNew) == words.end())
                {
                    // Not found, intialize vector
                    std::vector <int> nums = { value };
                    words[strNew] = nums;

                }
                else
                {
                    // Found and store new int in vector
                    words[strNew].push_back(value);
                }
                // Reset counter and break
                count = 0;
                break;
            }
            // Add to count after trimming string and assigning word to strNew
            count++;
        }
    }
    // Return the map
    return words;
}