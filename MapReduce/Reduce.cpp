#include "Reduce.h"
#include "FileManagement.h"
#include <filesystem>
#include <string>
using std::string;
using std::to_string;

//reduce function that accepts a string and vector of intergers and passes the string and the vector sum to the export function, returns 0 if it is able to add it to the file, 1 if not
int Reduce::reduce(string keyInput, vector<int> countInput)
{
    //creates a variable to hold the sum of the vector
    int reducedValue = 0;
    //loop to add the intergers from the vector together
    for (int aCount : countInput) {
        reducedValue = reducedValue + aCount;
    }
    //
    return exportReduce(keyInput,reducedValue);
}

int Reduce::exportReduce(string key, int reducedValue) {
    string outputFileName = theDir + "\\theOutput.txt";

    if (std::filesystem::exists(outputFileName))
    {}
    else 
    {
        int createOutput = FileManagement::createFile(outputFileName);
    }
    string key_value_pair="[\""+key+"\","+ to_string(reducedValue)+"]\n";
    int added=FileManagement::writeDataToFile(outputFileName,key_value_pair);
    return added;
}
