/*
This is the header file for the Sort class. This will contain all of the function declarations
for the program and its private members. The Sort class will look at the intermediate results to sort and aggregate them.
Then an intermediate file will be generated.
*/
#pragma once

#include <string>
#include <map>
#include <vector>

class Sort
{
public:

	// Default constructor
	Sort() = default;

	// Destructor
	~Sort() = default;

	std::map <std::string, std::vector<int>> create_word_map(std::string tempDir);
};