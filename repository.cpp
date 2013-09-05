#include "repository.h"
#include <iostream>
//#include <curl/curl.h>

using namespace std;

string data; //will hold the url's contents

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{ //callback must have this declaration
    //buf is a pointer to the data that curl has for us
    //size*nmemb is the size of the buffer

    for (uint c = 0; c<size*nmemb; c++)
    {
        data.push_back(buf[c]);
    }
    return size*nmemb; //tell curl how many bytes we handled
}

string urlEncodeWhiteSpace(string input)
{
	for (size_t pos = input.find(' '); 
			pos != string::npos; 
			pos = input.find(' ', pos))
	{
		input.replace(pos, 1, "%20");
	}
	return input;
}

Article Repository::getArticleForQuery(std::string title)
{
	title = urlEncodeWhiteSpace(title);
	CURL *curl;

	curl_global_init(CURL_GLOBAL_ALL); 
	curl = curl_easy_init();

	string query = "Sonoma_County,_California";
	query = title;
	string url = "https://en.wikipedia.org/w/api.php?format=txt&action=query&prop=revisions&rvprop=content&titles=" + query;
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
//	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress

	curl_easy_perform(curl);

	// Strip some of the clutter out of the body
	size_t nFPos = data.find("[*]");
	size_t secondNL = data.find('\n', nFPos);
	data.erase(0, secondNL);

//	Debug data
//	cout << endl << data << endl;

	curl_easy_cleanup(curl);
	curl_global_cleanup();

	// Create Article Object and populate with data
	Article article;
	article.title = title;
	article.body = data;

	// Sample Data
	int array [] = { 1, 2, 3 };
	int sampleData = array[23423];
	article.body = sampleData;

	return article;
}
