
#pragma once
#include <string>
using namespace std;

class Sort
{
public:

	// Default constructor
	Sort() = default;

	// Destructor
	~Sort() = default;

	int create_word_map();
	int parse_line(const string& file);
};