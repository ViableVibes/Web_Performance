#include "IMetric.hpp"

//////////////////////////////////////////////////////////////////////////////////////////
// TTFB function definitions

CURLcode TTFB::execute(CURL* curl, double& returned_time) {
	CURLcode result;
	result = curl_easy_getinfo(curl, CURLINFO_STARTTRANSFER_TIME, &returned_time);
	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Response_time function definitions

CURLcode Response_time::execute(CURL* curl, double& returned_time) {
	double connect_time;
	CURLcode result;
	result = curl_easy_getinfo(curl, CURLINFO_APPCONNECT_TIME, &connect_time);
	if (result != CURLE_OK) return result;
	double transfer_time;
	result = curl_easy_getinfo(curl, CURLINFO_STARTTRANSFER_TIME, &transfer_time);
	returned_time = transfer_time - connect_time;
	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////
