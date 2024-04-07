#include "FileManagement.h"

#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <streambuf>

string FileManagement::readDatafromFile(const string& filePath)
{
	if (!std::filesystem::exists(filePath)) {
		std::cerr << "error file path (" << filePath << ") not found!\n";
		return std::string();
	}

	// https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
	std::ifstream t(filePath);

	return string(std::istreambuf_iterator<char>(t), std::istreambuf_iterator<char>());
}

int FileManagement::writeDataToFile(const string& filePath, const string& data)
{
	if (!std::filesystem::exists(filePath))
		return 1;

	return 0;
}

int FileManagement::createDirectory(const string& dirPath)
{
	if (!std::filesystem::exists(dirPath))
		return 1;

	return 0;
}

int FileManagement::deleteDirectory(const string& dirPath)
{
	if (!std::filesystem::exists(dirPath))
		return 1;

	return 0;
}

int FileManagement::createFile(const string& filePath)
{
	if (!std::filesystem::exists(filePath))
		return 1;

	return 0;
}

int FileManagement::deleteFile(const string& filePath)
{
	if (!std::filesystem::exists(filePath))
		return 1;

	return 0;
}
