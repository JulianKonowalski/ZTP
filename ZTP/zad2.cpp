#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

#define no_questions 10

void clearBuffer(void) {
	while (getchar() != '\n');
}

char getrandchar(void) {
	srand(time(nullptr));	
	int offset = 'z' - 'a' + 1;
	char randchar = 'a' + rand() % offset;
	return randchar;
}

int game(void) {
	struct tm date;
	time_t now, before;
	time(&before);
	int failed = 0;
	int answer;
	char randchar = getrandchar();
	for (int i = 0; i < no_questions; ++i) {
		std::cout << randchar << std::endl;
		std::cin >> answer;
		clearBuffer();
		if (answer != randchar) {
			++failed;
			if (failed == 2) {
				throw std::runtime_error("two consecutive fails");
			}
			continue;
		}
		randchar = getrandchar();
		failed = 0;
		system("cls");
	}
	time(&now);
	return int(difftime(now, before));
}

int main(void) {
	while (true) {
		try {
			int time_s = game();
			std::cout << "this round took " << time_s << " seconds" << std::endl;
		}
		catch (std::runtime_error) {
			std::cout << "failed twice" << std::endl;
		}
		std::cout << "play again? y/n" << std::endl; //ten fragment mozna wstawic do catch'a "w ramach obslugi wyjatku"
		char answer;
		std::cin >> answer;
		if (answer == 'n') {
			std::cout << "exiting the program..." << std::endl;
			break;
		}
		system("cls");
	}
	return 0;
}