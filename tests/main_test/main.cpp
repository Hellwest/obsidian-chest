#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <oc.h>
#include <manager.h>

const std::vector<std::string> commands = { "ls", "generate", "read", "remove" };

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Provide a command\n";
		return -1;
	}

	Manager manager;

	const std::string command = std::string(argv[1]);

	if (std::find(commands.begin(), commands.end(), command) == commands.end()) {
		std::cout << "Unrecognized command: " << command << "\n";
		return -1;
	}

	if (command == "ls") {
		manager.ls();
	}

	if (command == "generate") {
		if (argc < 3) {
			std::cout << "Provide a password length\n";
			return -1;
		}

		int password_length = std::stoi(argv[2]);

		std::string result = OC::random_sequence(password_length);
		std::cout << result << "\n";

		manager.add_entry("test_service", "test_user", result);
	}

	if (command == "read") {
		if (argc < 3) {
			std::cout << "Provide a service name to read\n";
			return -1;
		}

		std::string service_name = std::string(argv[2]);

		manager.read_entry(service_name);
	}

	if (command == "remove") {
		if (argc < 3) {
			std::cout << "Provide a service name to remove\n";
			return -1;
		}

		std::string service_name = std::string(argv[2]);

		manager.remove_entry(service_name);
	}

	return 0;
}

