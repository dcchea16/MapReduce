/* 
This is the header file for the FileManagement class. This will contain all of the function declarations
for the program and its private members.
*/

#pragma once

#include <iostream>

using std::string;

class FileManagement
{
public:

	// Default constructor
	FileManagement() = default;

	// Destructor
	~FileManagement() = default;
	
	static string readDatafromFile(const string& filePath);
	static int writeDataToFile(const string& filePath, const string& data);

	static int createDirectory(const string& dirPath);
	static int readDirectory(const string& dirPath);
	static int readAllDirectoryFileContents(const string& dirPath);
	static int deleteDirectoryContents(const string& dirPath);

	static int createFile(const string& filePath);
	static int deleteFile(const string& filePath);
};
