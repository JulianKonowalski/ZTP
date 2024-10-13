#include <iostream>
#include <fstream>
#include <stack>
#include <unordered_set>

float calcLine(std::ifstream& file) {
	std::unordered_set<char> operations = { '+', '-', '*', '/' };
	std::stack<float> operands;
	std::streampos filePos;
	char currentChar;
	do {
		filePos = file.tellg();
		currentChar = file.get();
		if (currentChar == ' ' || currentChar == '\n' || currentChar == -1) {
			continue;
		}
		if (currentChar >= '0' && currentChar <= '9') {
			file.seekg(filePos);
			float number;
			file >> number;
			operands.push(number);
		}
		else if (operations.contains(currentChar)) {
			float numbers[2];
			for (int i = 0; i < 2; ++i) {
				if (operands.empty()) {
					throw std::runtime_error("Too many operations, the operand stack is empty!");
				}
				numbers[i] = operands.top();
				operands.pop();
			}
			switch (currentChar) {
			case '+':
				operands.push(numbers[1] + numbers[0]);
				break;
			case '-':
				operands.push(numbers[1] - numbers[0]);
				break;
			case '*':
				operands.push(numbers[1] * numbers[0]);
				break;
			case '/':
				if (numbers[0] == 0) {
					throw std::runtime_error("Division by 0!");
				}
				operands.push(numbers[1] / numbers[0]);
				break;
			}
		}
		else {
			throw std::runtime_error("Unrecognized token!");
		}
	} while (!file.eof() && currentChar != '\n');
	if (operands.empty()) {
		throw std::runtime_error("File ends with next line character!");
	}
	return operands.top();
}

std::vector<float> parse(std::ifstream& file) {
	std::vector<float> answers;
	while (!file.eof()) {
		answers.push_back(calcLine(file));
	}
	return answers;
}

template <typename T>
void printVector(std::vector<T> vec) {
	for (float i : vec) {
		std::cout << i << std::endl;
	}
}

//supports parentheses
int main(void) {
	std::ifstream file("test.txt");
	try {
		std::vector<float> answers = parse(file);
		std::cout << "Successfully parsed the file!" << std::endl;
		printVector<float>(answers);
	} catch (std::runtime_error& error) {
		std::cout << error.what() << std::endl;
	}
	return 0;
}