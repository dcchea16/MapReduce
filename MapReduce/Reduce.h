#pragma once

#include <iostream>
#include <vector>
using std::vector;
using std::string;
class Reduce
{
public:
    Reduce (string theDirInput)
    :theDir(theDirInput){};
    int reduce(string keyInput, vector<int> countInput);
private:
    string theDir;
    int exportReduce(string key, int reducedValue);


};
