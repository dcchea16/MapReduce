/* 
This is the header file for the FileManagement class. This will contain all of the function declarations
for the program and its private members. All filesystem accesses (read, writes, delete, create, etc) will
be managed here.
*/

#pragma once
#include <iostream>

using std::string;

class FileManagement
{
public:

	// Default constructor for FileManagement
	FileManagement() {};

	// Destructor for FileManagement
	~FileManagement() {};

	// Function that will create a directory, given a directory path as dirPath
	static int createDirectory(const string& dirPath);
	// Function that will create a directory, given a directory path as dirPath
	static int readDirectory(const string& dirPath);

	// Function that will read all file contents from a directory, given a directory path as dirPath
	static int readAllDirectoryFileContents(const string& dirPath);
	// Function that will delete all file contents from a directory, given a directory path as dirPath
	static int deleteDirectoryContents(const string& dirPath);

	// Function that will create a single file, given a file path as filePath
	static int createFile(const string& filePath);
	// Function that will delete a single file, given a file path as filePath
	static int deleteFile(const string& filePath);
	// Function that will read and output the data from a file as a string
	static string readDatafromFile(const string& filePath);
	// Function that will write to a file, given a file path as filePath and input as data
	static int writeDataToFile(const string& filePath, const string& data);
};
