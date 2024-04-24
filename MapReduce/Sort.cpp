#include "Sort.h"
#include "FileManagement.h"

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>


using namespace std;

std::map <std::string, std::vector<int>>  Sort::create_word_map(string tempDir)
{
    //get one file for all tuples
    FileManagement::readAllDirectoryFileContents(tempDir);
    ifstream input_file(tempDir + "\\allWords.txt");

    string line; //current line
    string part; //current part being examined when line divided into two parts at the comma, 
    string strNew; //word without any symbols
    int value; //value in tuple without any symbols
    int count = 0; // current loop through parts

    map<string, vector<int>> words;

    //get line in file
    while (getline(input_file, line)) {
        istringstream is(line);
        //separate word from integer/count
        while (getline(is, part, ',')) {
            //if first loop, remove quotation
            if (count == 0) {
                unsigned first = part.find("\"");
                unsigned last = part.find_last_of("\"");
                strNew = part.substr(first, last - first);
                if (strNew.front() == '"') {
                    strNew.erase(0, 1); // erase the first quotation
                }

            }
            //if second iteration, remove parenthesis, get integer value and add word and count to map
            else if (count == 1) {
                if (part.back() == ')') {

                    part.erase(part.size() - 1); // get rid of the closing parenthesis
                }
                value = stoi(part); //convert to int

                //since word and int are acquired, store in map.
                if (words.find(strNew) == words.end()) {
                    // not found, intialize vector
                    vector <int> nums = { value };
                    words[strNew] = nums;

                }
                else {
                    //found and store new int in vector
                    words[strNew].push_back(value);
                }
                //reset counter and break
                count = 0;
                break;
            }
            //add to count after trimming string and assigning word to strNew
            count++;
        }
    }

    return words;
}