#include <iostream>
#include <string>

#include <oc.h>
#include <default_manager.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Provide a password length\n";
		return -1;
	}

	int length = std::stoi(argv[1]);
	std::string result = OC::random_sequence(length);

	std::cout << result << "\n";

	DefaultManager* default_manager = new DefaultManager;

	default_manager->add_entry("test_service", "test_user", result);

	return 0;
}
