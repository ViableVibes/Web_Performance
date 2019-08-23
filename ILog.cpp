#include "ILog.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

//////////////////////////////////////////////////////////////////////////////////////////
// Helper function declarations
bool sort_time_asc(const std::pair<std::string,double> &a,
              const std::pair<std::string,double> &b);

bool sort_time_desc(const std::pair<std::string,double> &a,
            const std::pair<std::string,double> &b);

//////////////////////////////////////////////////////////////////////////////////////////
// Console_log function definitions

void Console_log::results_log(const std::vector<std::pair<std::string, double>> &results) const  {
	std::cout << "**********************************************\n";
	if (results.size() == 0) {
		std::cout << "No Results\n";
		return;
	}

	std::vector<std::pair<std::string, double>> sorted_results = results;
	std::sort(sorted_results.begin(), sorted_results.end(), sort_time_asc);

	std::cout << "Results (seconds):\n";
	for (std::size_t i = 0; i < sorted_results.size(); i++) {
		std::cout << sorted_results[i].first << ": ";
		std::cout << sorted_results[i].second << std::endl;
	}
	std::cout << "**********************************************\n";
}

void Console_log::errors_log(const std::vector<std::pair<std::string, std::string>> &errors) const {
	std::cout << "**********************************************\n";
	if (errors.size() == 0) {
		std::cout << "No Errors\n";
		std::cout << "**********************************************\n";
		return;
	}
	std::cout << "ERRORS:\n";
	for (std::size_t i = 0; i < errors.size(); i++) {
		std::cout << errors[i].first << ": ";
		std::cout << errors[i].second << std::endl;
	}
	std::cout << "**********************************************\n";
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
// Helper function definitions

bool sort_time_desc(const std::pair<std::string,double> &a,
              const std::pair<std::string,double> &b)
{
    return (a.second > b.second);
}

bool sort_time_asc(const std::pair<std::string,double> &a,
              const std::pair<std::string,double> &b)
{
    return (a.second < b.second);
}
//////////////////////////////////////////////////////////////////////////////////////////
