#include <iostream>
#include <string>
#include "os.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Provide a password length\n";
		return -1;
	}

	int length = std::stoi(argv[1]);
	std::string result = os::random_sequence(length);

	return 0;
}

