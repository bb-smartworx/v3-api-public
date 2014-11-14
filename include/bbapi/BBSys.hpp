//! B&B API System class
/*!
	This class is used to access system information
*/

#include <string>

class BBSys
{
private:

public:
	/** Identifier for ON */
	static const unsigned int ON;
	/** Identifier for OFF */
	static const unsigned int OFF;

	//! Get Temperature function
	/*!
		Returns the internal temperature of the CPU in degrees celsius
	*/
	int getTemperature();
	
	//! Get Voltage function
	/*!
		Returns the supply voltage to the board
	*/
	float getVoltage();

	//! Set User LED function 
	/*!
		Turns the User LED on or off
		\param state the state of the LED to set (on or off)
	*/
	void setUsrLed(unsigned int state);

};