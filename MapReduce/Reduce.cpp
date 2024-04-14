#include "Reduce.h"
#include "FileManagement.h"

void Reduce::exportReduce(string key, int reducedValue) {
    
	if (std::filesystem::exists(".\\" + "theOutput.txt"))
	{}
	else {
		int createOutput = FileManagement::createFile(".\\" + "theOutput.txt");
	}
    int added=FileManagement::writeDataToFile(".\\" + "theOutput.txt", key, reducedValue);
	if (added==0) {
		int createSuccess = FileManagement::createFile(".\\" + "SUCCESS.txt");
	}

}
