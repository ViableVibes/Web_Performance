#include "IFilter.hpp"
#include <algorithm>

//////////////////////////////////////////////////////////////////////////////////////////
// Ascending_time function definitions

// helper function
bool sort_time_asc(const std::pair<std::string,double> &a,
              const std::pair<std::string,double> &b)
{
    return (a.second < b.second);
}

void Ascending_time::filter_results(std::vector<std::pair<std::string, double>> &results) {
	std::sort(results.begin(), results.end(), sort_time_asc);
}

//////////////////////////////////////////////////////////////////////////////////////////
// Descending_time function definitions

// helper function
bool sort_time_desc(const std::pair<std::string,double> &a,
              const std::pair<std::string,double> &b)
{
    return (a.second < b.second);
}

void Descending_time::filter_results(std::vector<std::pair<std::string, double>> &results) {
	std::sort(results.begin(), results.end(), sort_time_desc);
}

//////////////////////////////////////////////////////////////////////////////////////////
