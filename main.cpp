#include "Net_time.hpp"
#include "IObtain_urls.hpp"
#include "ILog.hpp"
#include "IMetric.hpp"
#include <curl/curl.h>

#include <iostream>

int main() {

	// IObtain_urls subclasses
	Console_input console_input;
	File_input file_input("url-list.txt");

	// IMetric subclasses
	Response_time response_time;
	TTFB ttfb;

	// ILog subclasses
	Console_log console_log;
	File_log file_log1("results.txt");
	File_log file_log2("errors.txt");

	// Filter subclasses
	Ascending_time ascending_time;
	Descending_time descending_time;

	////////////////////////////////////////////////
	//examples

	// Net_time with urls from a file (url-list.txt), measuring response time,
	// logging to the console, and sorting by ascending times
	 Net_time net1(&file_input, &response_time, &console_log, &ascending_time);
	 std::cout << "Working on it...\n";
	 net1.execute();
	 net1.filter_results();
	 net1.results_log();
	 net1.errors_log();

	 // // Net_time with urls from the console, measuring TTFB, logging to a file (results.txt)
	 // // Logging errors to a file (errors.txt) and sorting by descending_time
	 //
	 // Net_time net2(&console_input, &ttfb , &file_log1);
	 // net2.set_filter(&descending_time);
	 // std::cout << "Working on it...\n";
	 // net2.execute();
	 // net2.filter_results();
	 // net2.results_log();
	 // net2.set_log(&file_log2);
	 // net2.errors_log();
	 // std::cout << "results.txt and errors.txt created\n";
}
