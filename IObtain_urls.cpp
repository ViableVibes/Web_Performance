#include "IObtain_urls.hpp"
#include <iostream>
#include <string>
#include <fstream>

//////////////////////////////////////////////////////////////////////////////////////////
// Command_line_input function definitions

std::vector<std::string> Console_input::obtain_urls() {
	std::vector<std::string> urls;
	std::string url_in = "";
	std::cout << "Enter the URLS to add (\"done\" to finish): \n";
	while (1) {
		std::cin >> url_in;
		if (url_in == "done") break;
		urls.push_back(url_in);
	}
	return urls;
};

//////////////////////////////////////////////////////////////////////////////////////////
// File_input function definitions

std::vector<std::string> File_input::obtain_urls() {
	std::vector<std::string> urls;

	std::ifstream in_file(_file_name);
    std::string url;

	if (in_file.is_open()) {
		while(1) {
	            getline(in_file, url);
	            urls.push_back(url);
				if(! in_file.eof()) break;
	    }
	}
	else {std::cout << "Error opening that file\n";}

	return urls;
};

//////////////////////////////////////////////////////////////////////////////////////////
