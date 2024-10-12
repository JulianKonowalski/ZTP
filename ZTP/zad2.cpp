#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

#define NO_QUESTIONS 10

char getRandChar(void) {
	srand(time(NULL));	
	int offset = 'z' - 'a' + 1;
	char randChar = 'a' + rand() % offset;
	return randChar;
}

int game(void) {
	struct tm date;
	time_t now, before;
	time(&before);
	int failed = 0;
	int answer;
	char randChar = getRandChar();
	for (int i = 0; i < NO_QUESTIONS; ++i) {
		std::cout << int(randChar) << std::endl;
		std::cin >> answer;
		if (answer != randChar) {
			++failed;
			if (failed == 2) {
				throw std::runtime_error("Two consecutive fails");
			}
			continue;
		}
		randChar = getRandChar();
		failed = 0;
		system("cls");
	}
	time(&now);
	return int(difftime(now, before));
}

int main(void) {
	bool running = true;
	while (running) {
		try {
			int time_s = game();
			std::cout << "This round took " << time_s << " seconds" << std::endl;
		}
		catch (std::runtime_error) {
			std::cout << "Failed twice" << std::endl;
		}
		std::cout << "Play again? y/n" << std::endl; //ten fragment mozna wstawic do catch'a "w ramach obslugi wyjatku"
		char answer;
		std::cin >> answer;
		if (answer == 'n') {
			std::cout << "Exiting the program..." << std::endl;
			break;
		}
		system("cls");
	}
	return 0;
}