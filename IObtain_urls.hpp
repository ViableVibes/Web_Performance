#ifndef IObtain_urls_H
#define IObtain_urls_H

#include <vector>
#include <string>

//////////////////////////////////////////////////////////////////////////////////////////
// Interface for generating URLs

class IObtain_urls {
public:
	virtual std::vector<std::string> obtain_urls() = 0;
	~IObtain_urls(){};
};

//////////////////////////////////////////////////////////////////////////////////////////

// Concrete classes

//////////////////////////////////////////////////////////////////////////////////////////
// The Console_input class retrieves URLs from the command line

class Console_input : public IObtain_urls {
public:
	std::vector<std::string> obtain_urls();
};

//////////////////////////////////////////////////////////////////////////////////////////
// The File_input class retrieves URLs from a given file

class File_input : public IObtain_urls {
private:
	std::string _file_name;

public:
	std::vector<std::string> obtain_urls();

	// For setting input file names
	File_input(std::string file_name) {_file_name = file_name;} // constructor takes name for file
	void set_file_name(std::string file_name) {_file_name = file_name;}
};

//////////////////////////////////////////////////////////////////////////////////////////

#endif
