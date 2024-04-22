
#pragma once
#include <string>
#include <map>
#include <vector>
using namespace std;

class Sort
{
public:

	// Default constructor
	Sort() = default;

	// Destructor
	~Sort() = default;

	std::map <std::string, std::vector<int>> create_word_map(string tempDir);
	
};