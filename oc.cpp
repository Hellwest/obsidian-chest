#include <chrono>
#include <random>

#include "oc.h"

std::string OC::random_sequence(int length) {
		uint64_t seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 generator(seed);

		std::string result;
		for (int i = 0; i < length; ++i) {
				int index = generator() % table_size;
				char character = OC::possible_chars[index];
				result += character;
		}

		return result;
};

