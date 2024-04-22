#pragma once

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Reduce
{
public:
	Reduce(string keyInput, vector<int> countInput);

private:
	int exportReduce(string key, int reducedValue);
};