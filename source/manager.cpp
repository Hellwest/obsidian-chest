#include <iostream>
#include <fstream>

#include <manager.h>

char delimiter(',');
std::string filename("./oc");

void Manager::add_entry(std::string service_name, std::string user_name, std::string password) {
	std::ofstream f;
	f.open(filename, std::ofstream::app);
	if (!f.is_open()) {
		std::cout << "Error: Failed to open a file\n";
		exit(1);
	}

	f << service_name << delimiter;
	f << user_name << delimiter;
	f << password << std::endl;

	std::cout << "Written successfully\n";
	f.close();
}

std::string Manager::read_entry(std::string service_name) {
	std::ifstream f;
	f.open(filename, std::ifstream::in);
	if (!f.is_open()) {
		std::cout << "Error: Failed to open a file\n";
		exit(1);
	}

	std::string line;
	for (; std::getline(f, line);) {
		std::size_t pos = line.find(delimiter);
		std::string service = line.substr(0, pos);
		if (service == service_name) {
			break;
		}
	}

	std::size_t service_pos = line.find(delimiter);
	std::string service = line.substr(0, service_pos);

	++service_pos; // avoid comma

	std::size_t username_pos = line.find(delimiter, service_pos);
	std::string username = line.substr(service_pos, username_pos - service_pos);

	++username_pos;

	std::size_t endl_pos = line.length();
	std::string password = line.substr(username_pos, endl_pos);

	f.close();

	return service;
}
