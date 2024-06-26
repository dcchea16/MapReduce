/*
This is the header file for the Reduce class. This will contain all of the function declarations
for the program and its private members. The Reduce class takes in a string key and a vector of numbers and
adds the numbers in the vector together to a single interger and outputs it to a file.
*/

#pragma once

#include <iostream>
#include <vector>
using std::string;
using std::vector;

class Reduce
{
public:
	// Constructor that takes in the directory that the export file
	// should be in and saves it as a class parameter, theDir
	Reduce(string theDirInput)
		:theDir(theDirInput) {};

	// Function that takes in the string key and vector of intergers, sums the vector,
	// and passes the sum and key to the export function to output it to a file
	int reduce(string keyInput, vector<int> countInput);

private:
	// Export function called by reduce function that accepts the key and vector sum,
	// it creates a file in the theDir directory if it does not exist and adds the key and interger to the file
	int exportReduce(string key, int reducedValue);

	// Variable to hold the directory that is used in the exportReduce function
	string theDir;
};
