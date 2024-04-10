#pragma once

#include <string>
using std::string;


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
		// Do some checks
		protocol_ = protocol;
	}



	void resource(const string& resource)
	{
		// Do some checks
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


};
