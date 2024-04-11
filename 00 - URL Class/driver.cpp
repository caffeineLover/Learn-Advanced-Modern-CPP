#include <iostream>
#include "URL.h"
using namespace std;



int main()
{
	URL myURL("https", "www.someurl.org");

	cout << myURL.url() << endl;

	URL yourURL("http://yahoo.com");
	cout << yourURL.resource() << endl;

	URL ourURL("twas brillig and the slithy toves");

	cout << "npos: " << string::npos << endl;

	return 0;
}