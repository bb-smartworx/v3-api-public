// This file is for generating html for configuring your app

// Standard includes 
#include <iostream>
#include <vector>
#include <string>
#include <string.h>

// includes for BBApi Modules
#include <bbapi/BBCgi.hpp>
#include <bbapi/BBConfig.hpp>
#include <bbapi/BBGpio.hpp>
#include <bbapi/BBHtml.hpp>


// include for module header
#include "module.h"

using namespace std;

// Main function for the index.cgi script
static void main_index(void)
{
	BBGpio out(BBGpio::OUT);
	BBGpio in0(BBGpio::IN0);
	BBGpio in1(BBGpio::IN1);
	BBHtml h;

	h.pageBegin(MODULE_TITLE);

	h.addTextField("Value to write to GPIO out", "out", out.read());
	h.addTextField("Value on GPIO In0", "in0", in0.read());
	h.addTextField("Value on GPIO In1", "in1", in1.read());

	h.addLineBreak();
	h.addSubmitButton("Apply");

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

	if(input_ok) 
	{
		h.addText("Value written OK\n");
		out.write(cgi.getInt("out"));
	}

	h.pageEnd();
	cgi.end();
}

int main(int argc, char *argv[])
{
	// code

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