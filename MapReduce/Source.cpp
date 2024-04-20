#include <iostream>
#include <string>
#include <filesystem>
#include "Sort.h"
namespace fs = std::filesystem;

#include "FileManagement.h"

int main() {
	std::cout << "Hello World!\n";

	std::string foobar = FileManagement::readDatafromFile(".\\inputs\\input1.txt");

	std::cout << "foobar: " << foobar << '\n';

	Sort sorting;
	sorting.create_word_map();

	return 0;
}