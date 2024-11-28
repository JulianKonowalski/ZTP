#include <iostream>
#include <fstream>
#include <deque>
#include <vector>

#define FILE_PATH "macierz.txt" //plik powinien konczyc sie enterem!

std::vector<std::vector<double>>* transpose(std::deque<std::deque<double>>* matrix) {

	size_t numOfRows = matrix->size();
	size_t numOfColumns = matrix->front().size();

	std::vector<std::vector<double>>* transposedMatrix = new std::vector<std::vector<double>>(numOfColumns, std::vector<double>(numOfRows));

	for (int i = 0; i < numOfRows; ++i) {
		std::deque<double> row = matrix->front();
		matrix->pop_front();
		for (int j = 0; j < numOfColumns; ++j) {
			transposedMatrix->at(j).at(i) = row.front();
			row.pop_front();
		}
	}

	return transposedMatrix;
}

std::vector<std::vector<double>>* loadMatrix(const std::string path) {
	std::deque<std::deque<double>>* matrix = new std::deque<std::deque<double>>;
	std::deque<double> row;

	std::ifstream stream(path, std::ifstream::in);
	while (stream.good() && !stream.eof()) {
		double in;
		stream >> in;
		row.push_back(in);
		if (stream.get() == '\n') { matrix->push_back(row); row.clear(); }
	}
	stream.close();

	return transpose(matrix);
}

void printMatrix(std::vector<std::vector<double>>* matrix) {
	for (int i = 0; i < matrix->size(); ++i) {
		for (int j = 0; j < matrix->at(0).size(); ++j) {
			std::cout << matrix->at(i).at(j) << " ";
		}
		std::cout << "\n";
	}
}

int main(void) {
	printMatrix(loadMatrix(FILE_PATH));
	return 0;
}