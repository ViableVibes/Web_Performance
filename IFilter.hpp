#ifndef IFilter_h
#define IFilter_h

#include <vector>
#include <string>

//////////////////////////////////////////////////////////////////////////////////////////
// Filter Inteface

class IFilter {
public:
	// Use the filter_results function to filter results after execute(s)
	virtual void filter_results(std::vector<std::pair<std::string, double>> &results) = 0;

	// Use the errors function to filter results after execute(s)
	virtual void filter_errors(std::vector<std::pair<std::string, int>> &errors){}; // If you'd like

	// Virtual destructor
	virtual ~IFilter(){};
};

//////////////////////////////////////////////////////////////////////////////////////////

//Concrete Classes

//////////////////////////////////////////////////////////////////////////////////////////
// The Ascending_time class filters results in ascending order

class Ascending_time : public IFilter {
	void filter_results(std::vector<std::pair<std::string, double>> &results);
};

//////////////////////////////////////////////////////////////////////////////////////////
// The Descending_time class filters results in ascending order

class Descending_time : public IFilter {
	void filter_results(std::vector<std::pair<std::string, double>> &results);
};

//////////////////////////////////////////////////////////////////////////////////////////

#endif
