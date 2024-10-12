#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <stdexcept>
#include <unordered_set>

std::unordered_set <char> decorators = {'_', '*', '`'}; //bez # bo to nie formatowanie czcionki

//chars = [*, **, _, __, `]
//
//if char in chars:
//	if not begFlag
//		begFlag = true
//		opened = char
//		continue
//	if char != opened:
//		throw exept
//	opened = null
//	begFlag = false

void parser(std::ifstream& file) {
	bool openFlag = false;
	char currentDecorator = 0;
	std::string openDecorator;
	while (!file.eof()) {
		currentDecorator = file.get();
		if (decorators.contains(currentDecorator)) {
			char tmp = file.get();
			if (!openFlag) { //open decorator
				if (decorators.contains(tmp) && tmp == currentDecorator && tmp != '`') {
					openDecorator = std::string(tmp, 2);
				} else if (!decorators.contains(tmp)) {
					openDecorator = std::string(currentDecorator, 1);
				} else {
					throw std::runtime_error("Wrong formatting");
				}
				openFlag = true;
			} else { //close decorator
				std::string closeDecorator;
				if (decorators.contains(tmp) && tmp == currentDecorator && tmp != '`') {
					closeDecorator = std::string(tmp, 2);
				} else if (!decorators.contains(tmp)) {
					closeDecorator = std::string(currentDecorator, 1);
				} else {
					throw std::runtime_error("Wrong formatting");
				}
				if (closeDecorator != openDecorator) {
					throw std::runtime_error("Wrong formatting");
				}
				openFlag = false;
			}
		}
	}
}

int main(void) {
	std::string filename = "test.txt";
	std::ifstream file(filename);
	try {
		parser(file);
		std::cout << "Success!";
	} catch(std::runtime_error& error) {
		std::cout << error.what();
	}
	return 0;
}