#include <iostream>
#include <fstream>
#include <stdio.h>

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

	std::string line = this->find_line(f, service_name);

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

void Manager::remove_entry(std::string service_name) {
	std::ifstream line_finder_stream;
	line_finder_stream.open(filename, std::ifstream::in);
	if (!line_finder_stream.is_open()) {
		std::cout << "Error opening the file\n";
		exit(1);
	}

	std::string line = this->find_line(line_finder_stream, service_name);

	line_finder_stream.close();

	std::ifstream file_reader_stream;
	file_reader_stream.open(filename, std::ifstream::in);
	std::ofstream temp;
	temp.open("./temp", std::ofstream::app);

	std::string temp_line;
	while (std::getline(file_reader_stream, temp_line)) {
		if (temp_line != line) {
			temp << temp_line << std::endl;
		}
	}

	temp.close();
	file_reader_stream.close();
	std::remove(filename.c_str());
	std::rename("./temp", filename.c_str());
}

std::string Manager::find_line(std::ifstream& f, std::string service_name) {
	for (std::string line; std::getline(f, line);) {
		std::cout << "Line: " << line << "\n";
		std::size_t pos = line.find(delimiter);
		std::string service = line.substr(0, pos);
		if (service == service_name) {
			return line;
		}
	}
}
