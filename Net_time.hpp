#ifndef Net_time_H
#define Net_time_H

#include <curl/curl.h>
#include "IObtain_urls.hpp"
#include "IMetric.hpp"
#include "ILog.hpp"
#include "IFilter.hpp"

class Net_time {
private:
	IObtain_urls* _obtain_urls;
	IMetric* _metric;
	ILog* _log;
	IFilter* _filter = nullptr;

	std::vector<std::string> _urlList;
	std::vector<std::pair<std::string, double>> _results;
	std::vector<std::pair<std::string, std::string>> _errors;

public:
	// Constructor requires (IObtain_urls, IMetric, ILog)
	Net_time(IObtain_urls* obtain_list, IMetric* metric, ILog* log);
	// Constructor with optional filter argument
	Net_time(IObtain_urls* obtain_urls, IMetric* metric, ILog* log, IFilter* filter);

	void update_urls(); // Replaces the URL list with a new retrieval
	void errors_log(); // Logs the errors from execution(s)
	void results_log(); // Logs the results from execution(s)
	void clear_results(); // Clears the results from execution(s)
	void filter_results(); // Applies a filter after an execution returns results

	void execute(); // Executes the query based on the set metric

	// Setters
	void set_obtain_urls(IObtain_urls* obtain_urls);
	void set_log(ILog* log);
	void set_metric(IMetric* metric);
	void set_filter(IFilter* filter);
};

#endif
