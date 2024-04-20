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
int Sort::parse_line(const string& fileName)
{
  /*  ifstream input_file(fileName);
    string line;

    while (getline(input_file, line)) {
        create_word_arrays(line);
    }*/

    return 0;
}

int Sort::create_word_map()
{
    //currently in input folder, need to implement FileManagement
    ifstream input_file(".\\inputs\\intermediary.txt");
    string line;

    string token;
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

    // write file
    ofstream outputFile;
    outputFile.open("output.txt" , std::ios_base::app);
   
    if (outputFile.is_open()) {
        for (const auto& pair : words) {
            outputFile << pair.first << ", [ ";
            for (int num : pair.second) {
                outputFile << num << " ";
            }
            outputFile << "]";
            outputFile << endl;
        }
        outputFile.close();
       
    }
    else {
        cerr << "Unable to open file for writing." << endl;
    }


    return 0;
}