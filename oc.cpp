#include "oc.h"

constexpr char OC::possible_chars[];

std::string OC::random_sequence(int length) {
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 generator(seed);

		std::string result;
		for (int i = 0; i < length; ++i) {
				int index = generator() % 62;
				char character = OC::possible_chars[index];
				result += character;
		}

		return result;
};

