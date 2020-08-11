#include "default_manager.h"

#include <iostream>
#include <fstream>

void DefaultManager::add_entry(std::string service_name, std::string user_name, std::string password) {
	std::ofstream f;
	f.open("./oc", std::ifstream::app);
	if (!f.is_open()) {
		std::cout << "Error: Failed to open a file\n";
		exit(1);
	}

	f << "Service: " << service_name << " | ";
	f << "Username: " << user_name << " | ";
	f << "Password: " << password << "\n";

	std::cout << "Written successfully\n";
	f.close();
}
