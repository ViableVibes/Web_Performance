#ifndef ILog_h
#define ILog_h

#include <string>
#include <vector>
#include <utility>

//////////////////////////////////////////////////////////////////////////////////////////
// Logging interface

class ILog {
public:
	// Use the results_log function for storing the results after an execute()
	virtual void results_log(const std::vector<std::pair<std::string, double>> &results) const = 0;

	// Use the results_log function for storing the results after an execute()
	virtual void errors_log(const std::vector<std::pair<std::string, std::string>> &errors) const = 0;

	// Virtual destructor
	virtual ~ILog(){};
};

//////////////////////////////////////////////////////////////////////////////////////////

//Concrete Classes

//////////////////////////////////////////////////////////////////////////////////////////
// The Console_log class logs results and errors to the console

class Console_log : public ILog {
public:
	void results_log(const std::vector<std::pair<std::string, double>> &results) const;
	void errors_log(const std::vector<std::pair<std::string, std::string>> &errors) const;
};

//////////////////////////////////////////////////////////////////////////////////////////
// The File_log class logs results and errors to an output file
// Important to change the file_name with set_file_name if doing multiple requests
// Or the previous file will be overwritten

class File_log : public ILog {
private:
	std::string _file_name;
public:
	void results_log(const std::vector<std::pair<std::string, double>> &results) const;
	void errors_log(const std::vector<std::pair<std::string, std::string>> &errors) const;

	// Additional functions for output file naming
	File_log(std::string file_name); // Constructor with name parameter
	void set_file_name(std::string file_name); // For changing ouput file name
};
//////////////////////////////////////////////////////////////////////////////////////////

#endif
