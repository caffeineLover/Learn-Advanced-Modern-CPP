#include <iostream>
#include "URL.h"
using namespace std;



int main()
{
	URL myURL("https", "www.someurl.org");

	cout << myURL.url() << endl;

	return 0;
}