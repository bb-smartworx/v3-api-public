#include <iostream>

#include <bbapi/BBSerial.hpp>
#include <bbapi/BBConfig.hpp>

#include "module.h"

using namespace std;

int main()
{
	BBConfig cfg(MODULE_SETTINGS, MODULE_NAME);
	cfg.load(); string str;

	BBSerial s(cfg.getSetting("device", str));

	s.setBaudrate(BBSerial::BAUD_19200);
	s.setStopbits(BBSerial::STOPBITS_1);
	s.setParity(BBSerial::PARITY_NONE);
	s.open();
	s.write(cfg.getSetting("text", str));
	s.close();
}