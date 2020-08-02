#pragma once

#include <cstdlib>
#include <time.h>
#include <random>

namespace oc {
	std::string random_sequence(int length) {
		std::string result;
		std::mt19937 gen;
	
		gen.seed(time(NULL));
		for (int i = 0; i < length; ++i) {
			int randomNumber = std::rand() % 26;
			char letter = 'a' + randomNumber;
			result += letter;
		}
		return result;
	}
}

