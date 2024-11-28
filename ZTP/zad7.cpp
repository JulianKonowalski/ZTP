#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

std::list<std::string>* loadFile(const std::string& path) {
	std::ifstream stream(path, std::ifstream::in);

	std::list<std::list<std::string>> words;
	std::list<std::string> row;

	while (stream.good() && !stream.eof()) {
		std::string word;
		stream >> word;
		row.push_back(word);
		if (stream.get() == '\n') { words.push_back(row); row.clear(); } //w tekscie zamiast \n po slowach sa spacje, wiec nie do konca dziala, idk kto tak pisze dokument
	}

	stream.close();

	for (std::list<std::string>& row : words) {
		row.sort();
	}

	std::list<std::string>* summedList = new std::list<std::string>;

	for (const std::list<std::string>& row : words) {
		for (const std::string& item : row) {
			summedList->push_back(item);
		}
	}

	return summedList;
}

void printList(std::list<std::string>* list) {
	for (const std::string& item : *list) {
		std::cout << item << "\n";
	}
}

int main(void) {
	printList(loadFile("mistrz.txt"));
	return 0;
}