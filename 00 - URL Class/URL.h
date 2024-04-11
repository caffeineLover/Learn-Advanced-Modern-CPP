#pragma once

#include <string>
using std::string;
using std::cerr;
using std::endl;


/*
	Because the class is so simple, I put everything into the header file.

	If this is all that there was (i.e. no error-checking) it would probably make sense
	for the class members to be public, but let's assume error checking is going to be
	done, so we'll keep them private and gateway access through getters and setters.
*/


class URL
{

private:
	string protocol_;
	string resource_;


public:

	URL(const string& protocol, const string& resource)
		: protocol_{ protocol }, resource_{ resource }
	{};


	URL(const string& url)
	{
		parse_url( url );
	}


	URL(const URL& other)
		: protocol_{ other.protocol_ }, resource_{ other.resource_ }
	{};


	URL& operator=(const URL& other)
	{
		protocol_ = other.protocol_;
		resource_ = other.resource_;

		return *this;
	}


	void protocol(const string& protocol)
	{
		// Pretend we're doing some checks
		protocol_ = protocol;
	}


	void resource(const string& resource)
	{
		// Pretend we're doing some checks
		resource_ = resource;
	}


	string& protocol()
	{
		return protocol_;
	}


	string& resource()
	{
		return resource_;
	}


	string url()
	{
		return protocol() + "://" + resource();
	}


	// For "http://www.yahoo.com", separatorPos will be 4 (the 'h' will be 0).
	//
	// string::npos is the largest integer representable by size_t.  When string::find()
	// can't find a match, it returns string::npos.
	//
	void parse_url(const string& url)
	{
		size_t separatorPos = url.find("://");

		if (separatorPos != string::npos) {
			protocol_ = url.substr(0, separatorPos);
			resource_ = url.substr(separatorPos + 3);  // skip "://"
		} else {
			cerr << "Malformed url: " << url << endl;
		}
	}

};
