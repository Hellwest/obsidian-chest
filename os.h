#pragma once

#include <stdlib.h>
#include <time.h>

namespace os {
	std::string random_sequence(int length) {
		int i = 0;
		int randomNumber;
		char letter;
		std::string result = "";

		std::srand(time(NULL));
		for (i = 0; i < length; i++) {
			randomNumber = std::rand() % 26;
			letter = 'a' + randomNumber;
			result[i] = letter;
		}
		return result;
	}
}

