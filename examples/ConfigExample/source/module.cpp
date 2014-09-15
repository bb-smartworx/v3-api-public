// This file is the "main" where the excution code should go

// Standard includes 
#include <iostream>

// includes for BBApi Modules
#include <bbapi/BBConfig.hpp>

// include for module header
#include "module.h"

using namespace std;

// Main
int main()
{
	BBConfig cfg(MODULE_SETTINGS, MODULE_NAME);
	cfg.load(); int i; bool b; string s; 

	cfg.setSetting("enabled", false);
	cfg.setSetting("ipaddr", "192.168.11.11");
	
	cfg.save();

	// code
	return 0;
}