#include <iostream>
#include "Map.h"
#include "FileManagement.h"

using std::string;
using std::cerr;
using std::cout;

int main(int argc, char* argv[]) {
	//checks if there are the correct number of inputs
	if (argc < 4) {
		cerr << "Error: Not enough inputs. \n";
		return 1; // Return error code
	}
	else if (argc > 4) {
		cerr << "Error: Too many inputs. \n";
		return 1; // Return error code
	}

	// Convert command-line arguments to appropriate types
	string inputDir = argv[1];
	string tempDir = argv[2];
	string outputDir = argv[3];

	if (!std::filesystem::exists(inputDir))
	{
		std::cerr << "error directory path (" << inputDir << ") doesn't exist!\n";
		return 1;
	}

	if (std::filesystem::is_empty(inputDir))
	{
		std::cerr << "directory path (" << inputDir << ") is empty!\n";
		return 1;
	}

	for (const auto& entry : std::filesystem::directory_iterator(inputDir))
	{
		string contents = readDatafromFile(entry.path().string());
		if (fileContent.empty())
		{
			cerr << entry.path().string()<<" is empty or could not be read.\n";
		}
		else {
			Map mapper;
			mapper.map(inputBaseName, fileContent);
		}
		
	}
	for (const auto& entry : std::filesystem::directory_iterator(tempDir))
	{
		string contents = readDatafromFile(entry.path().string());
		if (fileContent.empty())
		{
			cerr << entry.path().string() << " is empty or could not be read.\n";
		}
		else {
			//the sorting
			try {
				std::filesystem::current_path(outputDir);
				//loop for the reduce
			}
			catch (const std::filesystem::filesystem_error& e) {
				std::cerr << "Failed to change directory: " << e.what() << std::endl;
			}
			
		}

	}


	std::string foobar = FileManagement::readDatafromFile(".\\inputs\\input1.txt");

	std::cout << "foobar: " << foobar << '\n';

	cout << "Mapping completed. Check the temp directory for output.\n";
}
