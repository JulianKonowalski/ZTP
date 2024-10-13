#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

#define NO_QUESIONS 10

inline void clearBuffer(void) {
	while (getchar() != '\n');
}

char getrandchar(void) {
	srand(time(nullptr));	
	int offset = 'z' - 'a' + 1;
	return 'a' + rand() % offset;
}

int game(void) {
	time_t now, before;
	time(&before);
	int answer, failed = 0;
	char randchar = getrandchar();
	for (int i = 0; i < NO_QUESIONS; ++i) {
		std::cout << randchar << std::endl;
		std::cin >> answer;
		clearBuffer();
		if (answer != randchar) {
			++failed;
			if (failed == 2) {
				throw std::runtime_error("two consecutive fails");
			}
			system("cls");
			std::cout << "Try again: ";
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
			std::cout << "This round took " << time_s << " seconds" << std::endl;
		}
		catch (std::runtime_error& error) {
			std::cout << error.what() << std::endl;
		}
		std::cout << "Play again? y/n" << std::endl; //ten fragment mozna wstawic do catch'a "w ramach obslugi wyjatku"
		if (getchar() == 'n') {
			std::cout << "Exiting the program..." << std::endl;
			break;
		}
		clearBuffer();
		system("cls");
	}
	return 0;
}