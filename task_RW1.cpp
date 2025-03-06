#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::string str;
	std::ifstream input_file;

	input_file.open("input1.txt");
	if (input_file.is_open()) {
		std::getline(input_file, str, '\0');
		input_file >> str;
		input_file.close();
		std::cout << str;
	}
}