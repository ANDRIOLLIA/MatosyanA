#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream input_file;
	input_file.open("input2.txt");
	std::string str;
	if (input_file.is_open()) {
		std::getline(input_file, str, '\0');
		input_file >> str;
		input_file.close();
		std::cout << str;
	}

}