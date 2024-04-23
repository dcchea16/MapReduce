#include "FileManagement.h"

#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <streambuf>

// Function that will create a directory, given a directory path as dirPath
int FileManagement::createDirectory(const string& dirPath)
{
	// Check if the directory path already exists
	if (std::filesystem::exists(dirPath))
	{
		std::cerr << "Error directory path (" << dirPath << ") already exists!\n";
		return 1;
	}

	std::filesystem::create_directory(dirPath);
	return 0;
}

// Function that will check if a directory exists, given a directory path as dirPath
int FileManagement::readDirectory(const string& dirPath)
{
	// Check if the directory path exists
	if (!std::filesystem::exists(dirPath))
	{
		return 1;
	}

	return 0;
}

// Function that will read all file contents from a directory, given a directory path as dirPath
int FileManagement::readAllDirectoryFileContents(const string& dirPath)
{
	// Check if the directory path exists
	if (!std::filesystem::exists(dirPath))
	{
		std::cerr << "error directory path (" << dirPath << ") doesn't exist!\n";
		return 1;
	}
	// Check if the directory path is empty
	if (std::filesystem::is_empty(dirPath))
	{
		std::cerr << "directory path (" << dirPath << ") is empty!\n";
		return 1;
	}

	std::ofstream outputFile;
	FileManagement::createFile(dirPath + "\\allWords.txt");

	for (const auto& entry : std::filesystem::directory_iterator(dirPath))
	{
		string contents = readDatafromFile(entry.path().string());

		FileManagement::writeDataToFile(dirPath + "\\allWords.txt", contents);
	}
}

// Function that will delete all file contents from a directory, given a directory path as dirPath
int FileManagement::deleteDirectoryContents(const string& dirPath)
{
	// Check if the directory path exists
	if (!std::filesystem::exists(dirPath))
	{
		std::cerr << "Error directory path (" << dirPath << ") doesn't exist!\n";
		return 1;
	}
	// Check if the directory path empty
	if (std::filesystem::is_empty(dirPath))
	{
		return 1;
	}

	// Iterate through all the directory files and delete them
	for (const auto& entry : std::filesystem::directory_iterator(dirPath))
	{
		std::filesystem::remove_all(entry.path());
	}

	return 0;
}

// Function that will create a single file, given a file path as filePath
int FileManagement::createFile(const string& filePath)
{
	// Check if the file path exists
	if (std::filesystem::exists(filePath))
	{
		std::cerr << "Error file path (" << filePath << ") already exists!\n";
		return 1;
	}

	// Create the file with the name given by filePath
	std::ofstream ofs(filePath);
	ofs.close();
	return 0;
}

// Function that will delete a single file, given a file path as filePath
int FileManagement::deleteFile(const string& filePath)
{
	// Check if the file path exists
	if (!std::filesystem::exists(filePath))
	{
		std::cerr << "Error file path (" << filePath << ") does not exist\n";
		return 1;
	}

	// Remove file with the name given by filePath
	std::filesystem::remove(filePath);
	return 0;
}

// Function that will read and output the data from a file as a string
string FileManagement::readDatafromFile(const string& filePath)
{
	// Check if the file path exists
	if (!std::filesystem::exists(filePath))
	{
		std::cerr << "Error file path (" << filePath << ") not found!\n";
		return string();
	}
	// Check if the file path is empty
	else if (std::filesystem::is_empty(filePath))
	{
		std::cerr << "Error file path (" << filePath << ") is empty!\n";
		return string();
	}

	// Read the file's contents and return as a string
	std::ifstream t(filePath);
	return string(std::istreambuf_iterator<char>(t), std::istreambuf_iterator<char>());
}

// Function that will write to a file, given a file path as filePath and input as data
int FileManagement::writeDataToFile(const string& filePath, const string& data)
{
	// Check if the file path exists
	if (!std::filesystem::exists(filePath))
	{
		std::cerr << "Error file path (" << filePath << ") not found!\n";
		return 1;
	}

	// Write data to the file, given by the filePath and the data provided
	std::ofstream ofs(filePath, std::ios_base::app);
	ofs << data;
	ofs.close();
	return 0;
}