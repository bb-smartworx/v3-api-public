// This file is for generating html for configuring your app

// Standard includes 
#include <iostream>

// includes for BBApi Modules
#include <bbapi/BBCgi.hpp>
#include <bbapi/BBHtml.hpp>

// includes for module header
#include "module.h"

using namespace std;

// Main function for the index.cgi script
static void main_index(void)
{
	BBHtml h;

	h.pageBegin(MODULE_TITLE);

	// Build your web page


	h.pageEnd();
}

static void main_set(void)
{
	BBCgi cgi;
	BBGpio out(BBGpio::OUT);
	BBHtml h;
	int input_ok;

	cgi.begin();
	h.pageBegin(MODULE_TITLE);

	input_ok = cgi.query_ok();

	// Get values from the form


	if(input_ok) 
	{
		
	}

	h.pageEnd();
	cgi.end();
}

int main(int argc, char *argv[])
{
	string name;

	if (argc > 0) 
	{
		name = string(basename(argv[0]));
		if (!name.compare("index.cgi")) 
		{
			main_index();
		} 
		else if (!name.compare("set.cgi")) 
		{
			main_set();
		}
	}

	return 0;
}