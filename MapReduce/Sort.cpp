#include "Sort.h"
#include "FileManagement.h"
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

std::map <std::string, std::vector<int>>  Sort::create_word_map(string tempDir)
{
    std::cout << "create word map \n";
    std::cout << "this is the temp dir: " + tempDir << "\n";
    FileManagement::readAllDirectoryFileContents(tempDir);
    ifstream input_file("allWords.txt");
    string line;
    string part;
    string strNew;
    int value;
    int count = 0;
    map<string, vector<int>> words;

    //get line
    while (getline(input_file, line)) {
        istringstream is(line);
        //seperate word from count
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
            //if second iteration, remove paranthesis, get integer value and add word and count to map
            else if (count == 1) {
                if (part.back() == ')') {

                    part.erase(part.size() - 1); // erase the last character
                }
                value = stoi(part);

                if (words.find(strNew) == words.end()) {
                    // not found
                    vector <int> nums = { value };
                    words[strNew] = nums;

                }
                else {
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