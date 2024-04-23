#include "Reduce.h"
#include "FileManagement.h"
#include <filesystem>
#include <string>
using std::string;
using std::to_string;


void Reduce::reduce(string keyInput, vector<int> countInput)
{
    int reducedValue = 0;
    for (int aCount : countInput) {
        reducedValue = reducedValue + aCount;
    }
    exportReduce(keyInput, reducedValue);
}


int Reduce::exportReduce(string key, int reducedValue) {

    if (std::filesystem::exists(theDir + "\theOutput.txt"))
    {
    }
    else {
        int createOutput = FileManagement::createFile(theDir + "\theOutput.txt");
    }
    string key_value_pair = "[\" " + key + "\"," + to_string(reducedValue) + "]\n";
    int added = FileManagement::writeDataToFile(theDir + "\theOutput.txt", key_value_pair);
    return added;

}