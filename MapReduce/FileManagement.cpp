#include "FileManagement.h"
#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <streambuf>
#include <sstream>

string FileManagement::readDatafromFile(const string& filePath)
{
	if (!std::filesystem::exists(filePath))
	{
		std::cerr << "error file path (" << filePath << ") not found!\n";
		return string();
	}
	else if (std::filesystem::is_empty(filePath))
	{
		std::cerr << "error file path (" << filePath << ") is empty!\n";
		return string();
	}

	// https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
	std::ifstream t(filePath);
	return string(std::istreambuf_iterator<char>(t), std::istreambuf_iterator<char>());
}

int FileManagement::writeDataToFile(const string& filePath, const string& data)
{
	if (!std::filesystem::exists(filePath))
	{
		std::cerr << "error file path (" << filePath << ") not found!\n";
		return 1;
	}

	std::ofstream ofs(filePath, std::ios_base::app);
	ofs << data;
	ofs.close();
	return 0;
}

int FileManagement::createDirectory(const string& dirPath)
{
	if (std::filesystem::exists(dirPath))
	{
		std::cerr << "error directory path (" << dirPath << ") already exists!\n";
		return 1;
	}

	std::filesystem::create_directory(dirPath);
	return 0;
}

//TODO
int FileManagement::readAllDirectoryFileContents(const string& dirPath)
{
	if (!std::filesystem::exists(dirPath))
	{
		std::cerr << "error directory path (" << dirPath << ") doesn't exist!\n";
		return 1;
	}

	if (std::filesystem::is_empty(dirPath))
	{
		std::cerr << "directory path (" << dirPath << ") is empty!\n";
		return 1;
	}
	// Create a temp file to write to?
	std::ofstream outputFile;
	outputFile.open("output1.txt", std::ios_base::app);
	for (const auto& entry : std::filesystem::directory_iterator(dirPath))
	{
		string contents = readDatafromFile(entry.path().string());


		outputFile << contents;
		outputFile << '\n';
	}
}

int FileManagement::deleteDirectoryContents(const string& dirPath)
{
	if (!std::filesystem::exists(dirPath))
	{
		std::cerr << "error directory path (" << dirPath << ") doesn't exist!\n";
		return 1;
	}

	if (std::filesystem::is_empty(dirPath))
	{
		std::cerr << "directory path (" << dirPath << ") is already empty!\n";
		return 1;
	}

	for (const auto& entry : std::filesystem::directory_iterator(dirPath))
	{
		std::filesystem::remove_all(entry.path());
	}

	return 0;
}

int FileManagement::createFile(const string& filePath)
{
	if (std::filesystem::exists(filePath))
	{
		std::cerr << "error file path (" << filePath << ") already exists!\n";
		return 1;
	}

	std::ofstream ofs(filePath);
	ofs.close();
	return 0;
}

int FileManagement::deleteFile(const string& filePath)
{
	if (!std::filesystem::exists(filePath))
	{
		std::cerr << "error file path (" << filePath << ") already exists!\n";
		return 1;
	}

	std::filesystem::remove(filePath);
	return 0;
}