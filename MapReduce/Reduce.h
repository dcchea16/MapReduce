#pragma once

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Reduce
{
public:
	int reduce(string keyInput, vector<int> countInput);

private:
	int exportReduce(string key, int reducedValue);
};