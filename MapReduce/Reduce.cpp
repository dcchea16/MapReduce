#include "Reduce.h"
#include "FileManagement.h"
#include <filesystem>
#include <string>
using std::string;
using std::to_string;

int Reduce::reduce(string keyInput, vector<int> countInput)
{
    int reducedValue = 0;
    for (int aCount : countInput) {
        reducedValue = reducedValue + aCount;
    }
    return exportReduce(keyInput,reducedValue);
}

int Reduce::exportReduce(string key, int reducedValue) {
    
    string outputFileName = theDir + "theOutput.txt";
    if (std::filesystem::exists(outputFileName))
    {}
    else 
    {
        int createOutput = FileManagement::createFile(outputFileName);
    }
    string key_value_pair="[\" "+key+"\","+ to_string(reducedValue)+"]\n";
    int added=FileManagement::writeDataToFile(outputFileName,key_value_pair);
    return added;
}