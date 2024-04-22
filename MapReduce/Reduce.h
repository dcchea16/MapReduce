#pragma once

#include <iostream>
#include <vector>
using std::vector;
class Reduce
{
public:
	Reduce(string keyInput, vector<int> countInput) 
	{
		int reducedValue = 0;
		for (int aCount : count) {
			reducedValue = reducedValue + aCount;
		}
		exportReduce(keyInput,reducedValue);
	}
private:
	void exportReduce(string key, int reducedValue);


};

