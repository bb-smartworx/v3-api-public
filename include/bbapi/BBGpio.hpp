//! B&B API GPIO class
/*!
	This class lets you read and write data from the GPIO port on the V3 router
*/

#include <iostream>

class BBGpio
{
private:
	int device;

public:
	/** Identifier for out */
	static const int OUT;
	/** Identifier for in0 */
	static const int IN0;
	/** Identifier for in1 */
	static const int IN1;

	//! Constructor for the gpio object
	/*!
		The constructor takes an integer that corresponds to the name of the device, 
		Usage:  BBGpio g_out(BBGpio::OUT);
				BBGpio g_in0(BBGpio::IN0);
				BBGpio g_in1(BBGpio::IN1);
		Any other value will give an error.
	*/
	BBGpio(int dev);

	// //! Open port function
	// !
	// 	Open the port with the set pararmeters. The port must be configured before it is opened.
	// 	The port must be opened before it can be written to or read from.
	
	// int open();

	// //! Close port function
	// /*!
	// 	Closes the serial port. Applications must call close when finished with the port
	// */
	// int close();

	//! Write function
	/*!
		Writes the given value to the gpio out port
		\param out the value that will be written to the port, can be 1 or 0 only
	*/
	void write(unsigned int out);
	
	//! Read function
	/*!
		Reads data from the gpio in port and returns it.
	*/
	int read();
};

extern "C"
{
     BBGpio* gpio_ctypes(int gpio_number){ return new BBGpio(gpio_number); }

     int write_ctypes(BBGpio* temp, unsigned int binary){ temp->write(binary); }
     int read_ctypes(BBGpio* temp){ temp->read(); }
}