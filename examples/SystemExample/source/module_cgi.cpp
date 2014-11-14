// This file is for generating html for configuring your app

// Standard includes 
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>

// includes for BBApi Modules
#include <bbapi/BBSys.hpp>
#include <bbapi/BBHtml.hpp>

// include for module header
#include "module.h"

using namespace std;

// Main function for the index.cgi script
static void main_index(void)
{
	BBSys s;
	BBHtml h;

	h.pageBegin(MODULE_TITLE);

	stringstream sstemp;
	sstemp << "Temperature: " << s.getTemperature() << " C";
	h.addText(sstemp.str());

	stringstream ssvolt;
	ssvolt << "Voltage: " << s.getVoltage() << " V";
	h.addText(ssvolt.str());

	h.addText("User LED should be flashing for twenty seconds");

	h.addLineBreak();

	h.pageEnd();

	for (int i = 0; i < 10; i++)
	{
		s.setUsrLed(BBSys::ON);
		sleep(1);
		s.setUsrLed(BBSys::OFF);
		sleep(1);
	}
	s.setUsrLed(BBSys::OFF);
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
	}

	return 0;
}
