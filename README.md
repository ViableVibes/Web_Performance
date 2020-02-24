--To Run --

sudo apt-get install libcurl4-openssl-dev

g++ *.cpp -lcurl -o net_time

./net_time

--To Customize--

The classes in this project were designed with extensibility in mind. There are limited dependencies between classes, so functionality can be added to one area without affecting the others. 

-Log: Change the way your results are stored/outputted

-Obtain_urls: Change the way your websites to track are obtained

-Metric: Change your metric(s) to track. https://curl.haxx.se/libcurl/c/curl_easy_getinfo.html for more info.

