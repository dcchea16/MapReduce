#include <iostream>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

#include "FileManagement.h"

int main() {

	std::string testZero = FileManagement::readDatafromFile(".\\inputs\\input1.txt");

	std::cout << "testZero: " << testZero << '\n';

	//int testOne = FileManagement::createDirectory("temp");
	//int testTwo = FileManagement::createFile(".\\temp\\inputHere.txt");
	//int testThree = FileManagement::writeDataToFile(".\\temp\\inputHere.txt", "i wrote something here");
	//int testFour = FileManagement::createFile(".\\temp\\inputThere.txt");
	//int testFive = FileManagement::deleteFile(".\\temp\\inputThere.txt");
	//int testSix = FileManagement::deleteDirectory("temp");

	return 0;
}