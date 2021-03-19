#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <getopt.h>

#include <oc.h>
#include <manager.h>

const std::vector<std::string> commands = { "ls", "add", "generate", "read", "remove" };
const char* short_opts = "s:n:p:";
const option long_opts[] = {
	{"service", required_argument, nullptr, 's'},
	{"name", required_argument, nullptr, 'n'},
	{"password", required_argument, nullptr, 'p'},
};

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

	if (command == "add") {
		int res = 0;
		std::string service;
		std::string name;
		std::string password;
		while ((res = getopt_long(argc, argv, short_opts, long_opts, nullptr)) != -1) {
			switch (res) {
				case 's':
					service = optarg;
					continue;
				case 'n':
					name = optarg;
					continue;
				case 'p':
					password = optarg;
					continue;
				case '?':
					std::cout << "Unknown option character: " << optarg << "\n";
					return -1;
			}
		}
		if (service == "" || name == "" || password == "") {
			std::cout << "Missing one of the arguments: service, name, password\n";
			return -1;
		}
		manager.add_entry(service, name, password);
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

