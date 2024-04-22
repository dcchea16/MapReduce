#pragma once

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Reduce
{
public:
	Reduce(string theDirInput)
		:theDir(theDirInput) {};
	int reduce(string keyInput, vector<int> countInput);

private:
	int exportReduce(string key, int reducedValue);
	string theDir;
};