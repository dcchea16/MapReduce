#include <iostream>
#include <string>
#include <filesystem>
#include <map>
#include <vector>
#include <fstream>
#include "Sort.h"
namespace fs = std::filesystem;

#include "FileManagement.h"

int main() {
	std::cout << "Hello World!\n";

	std::string foobar = FileManagement::readDatafromFile(".\\inputs\\input1.txt");

	std::cout << "foobar: " << foobar << '\n';


    //word count map
	Sort sorting;
	std::map <std::string, std::vector<int>> wordCount = sorting.create_word_map();;


    //goes through a prints each word and number in int vector
    for (const auto& pair : wordCount) {
        cout << pair.first << " ";
        for (int num : pair.second) {
            cout << num << " ";
        }
        cout << '\n';
    }


	return 0;
}