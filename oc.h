#pragma once

#include <chrono>
#include <random>

namespace oc {
	std::string random_sequence(int length) {
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 generator(seed);

		std::string result;
		for (int i = 0; i < length; ++i) {
			char x = generator() % 62;
			if(x < 10) {
				x+= '0';
			} else if(x < 36) {
				x += 'A' - 10;
			} else {
				x += 'a' - 36;
			}
			result += x;
		}

		return result;
	}
}

