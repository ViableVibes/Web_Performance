#include "ILog.hpp"
#include <iostream>
#include <fstream>

//////////////////////////////////////////////////////////////////////////////////////////
// Console_log function definitions

void Console_log::results_log(const std::vector<std::pair<std::string, double>> &results) const  {
	if (results.size() == 0) {
		std::cout << "No Results\n";
		return;
	}
	std::cout << "Results (seconds):\n";
	for (std::size_t i = 0; i < results.size(); i++) {
		std::cout << results[i].first << ": ";
		std::cout << results[i].second << std::endl;
	}
}

void Console_log::errors_log(const std::vector<std::pair<std::string, std::string>> &errors) const {
	if (errors.size() == 0) {
		std::cout << "No Errors\n";
		return;
	}
	std::cout << "ERRORS:\n";
	for (std::size_t i = 0; i < errors.size(); i++) {
		std::cout << errors[i].first << ": ";
		std::cout << errors[i].second << std::endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
// File_log function definitions

void File_log::results_log(const std::vector<std::pair<std::string, double>> &results) const  {
	std::ofstream out_file(_file_name);
	if (out_file.is_open()) {
		if (results.size() == 0) {
			out_file << "No Results\n";
			return;
		}
		out_file << "Results (seconds):\n";
		for (std::size_t i = 0; i < results.size(); i++) {
			out_file << results[i].first << ": ";
			out_file << results[i].second << std::endl;
		}
	}
	else std::cout << "Error writing to that file\n";

	out_file.close();

}

void File_log::errors_log(const std::vector<std::pair<std::string, std::string>> &errors) const {
	std::ofstream out_file(_file_name);
	if (out_file.is_open()) {
		if (errors.size() == 0) {
			out_file << "No Errors";
			return;
		}
		out_file << "ERRORS:\n";
		for (std::size_t i = 0; i < errors.size(); i++) {
			out_file << errors[i].first << ": ";
			out_file << errors[i].second << std::endl;
		}
	}
	else std::cout << "Error writing to that file\n";
	out_file.close();
}

File_log::File_log(std::string file_name) {_file_name = file_name;}
void File_log::set_file_name(std::string file_name) {_file_name = file_name;}

//////////////////////////////////////////////////////////////////////////////////////////
