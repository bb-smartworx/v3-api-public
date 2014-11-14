//! B&B API Serial class
/*!
	This class lets you read and write data from the RS232 Expansion port on the V3 router
*/


#include <iostream>
#include <string>

class BBSerial
{
private:
	int baudrate;
	int stopbits;
	int parity;
	// int flowctrl;
	int databits;
	
	int fd;
	std::string dev;	

public:
	/** 9600 baudrate */
	static const unsigned int BAUD_9600;
	/** 19200 baudrate */
	static const unsigned int BAUD_19200;
	/** 38400 baudrate */
	static const unsigned int BAUD_38400;
	/** 57600 baudrate */
	static const unsigned int BAUD_57600;
	/** 115200 baudrate */
	static const unsigned int BAUD_115200;
	/** 230400 baudrate */
	static const unsigned int BAUD_230400;

	/** 5 date bit format */
	static const int DATABITS_5;
	/** 6 date bit format */
	static const int DATABITS_6;
	/** 7 date bit format */
	static const int DATABITS_7;
	/** 8 date bit format */
	static const int DATABITS_8;

	// static const int FLOWCONTROL_NONE;
	// static const int FLOWCONTROL_CCTS_OFLOW;
	// static const int FLOWCONTROL_CRTS_IFLOW;

	/** 1 stopbits */
	static const int STOPBITS_1;
	/** 2 stopbits */
	static const int STOPBITS_2;

	/** No parity bit */
	static const int PARITY_NONE;
	/** Odd parity */
	static const int PARITY_ODD;
	/** Even parity */
	static const int PARITY_EVEN;

	//! Constructor for the serial object
	/*!
		The constructor takes a string that is the name of the device, 
		e.g BBSerial s("/dev/ttyS1")
		Defaults to /dev/ttyS0 if given an incorrect value.
	*/
	BBSerial(std::string dev);
	
	//! Constructor for the serial object
	/*!
		The constructor takes an int that is the number of the port, 
		e.g BBSerial s(1)
		Defaults to 0 (/dev/ttyS0) if given an incorrect value.
	*/
	BBSerial(int port);

	//! Set the baudrate function
	/*!
		Sets the baudrate for the serial port. Defaults to 9600
		\param b the baudrate to set
	*/
	void setBaudrate(int b){baudrate = b;}
	
	//! Set the stopbits function
	/*!
		Sets the stopbits for the serial port
		\param s the stopbits to set
	*/
	void setStopbits(int s){stopbits = s;}
	
	//! Set the parity function
	/*!
		Sets the parity for the serial port
		\param p the parity to set
	*/
	void setParity(int p){parity = p;}

	// void setFlowctrl(int f){flowctrl = f;}

	//! Set the databits function
	/*!
		Sets the databits for the serial port
		\param d the databits to set
	*/
	void setDatabits(int d){databits = d;}

	//! Get the baudrate function
	/*!
		Returns the current baudrate for the serial port
	*/
	int getBaudrate(){return baudrate;}
	
	//! Get the stopbits function
	/*!
		Returns the current stopbits for the serial port
	*/
	int getStopbits(){return stopbits;}

	//! Get the parity function
	/*!
		Returns the current parity for the serial port
	*/
	int getParity(){return parity;}

	// int getFlowctrl(){return flowctrl;}

	//! Get the databits function
	/*!
		Returns the current databits for the serial port
	*/
	int getDatabits(){return databits;}

	//! Open port function
	/*!
		Open the port with the set pararmeters. The port must be configured before it is opened.
		The port must be opened before it can be written to or read from.
	*/
	int open();

	//! Close port function
	/*!
		Closes the serial port. Applications must call close when finished with the port
	*/
	int close();

	//! Write function
	/*!
		Writes the given the given string to the serial port
		\param toSend the string that will be written to the port
	*/
	int write(std::string toSend);
	
	//! Write function
	/*!
		Writes the given the given char array to the serial port
		\param toSend the char array that will be written to the port
	*/
	int write(unsigned char toSend[]);

	//! Read function
	/*!
		Reads data from the serial port and returns it as a string
	*/
	std::string read();
};