#pragma once

#include <string>

class Manager {
	public:
		void add_entry(std::string service_name, std::string user_name, std::string password);
		std::string read_entry(std::string service_name);
		void remove_entry(std::string service_name);
};
