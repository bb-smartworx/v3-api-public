//! B&B API CGI Helper class
/*!
	This class is used to interface with the CGI scripts that are used to build webpages. Use this class to retrive input data from HTML forms.
*/

#ifndef BB_CGI_H
#define BB_CGI_H

#include <string>

class BBCgi
{
public:
	//! Begin function
	/*!
		Starts the CGI retriver
	*/
	void 	begin();
	
	//! End function
	/*!
		Stops the CGI retriver
	*/
	void 	end();

	//! Check query function
	/*!
		Checks if the CGI query is okay. Returns a 0 on sucess and 1 on failure.
	*/
	int 	query_ok();
	
	//! Retrive boolean function
	/*!
		Returns the boolean value of the html input with the given name 
		\param name the name of the html input, this name needs to match the one given to the input
	*/
	bool 		getBool(std::string name);
	
	//! Retrive integer function
	/*!
		Returns the integer value of the html input with the given name 
		\param name the name of the html input, this name needs to match the one given to the input
	*/
	int 		getInt(std::string name);

	//! Retrive string function
	/*!
		Returns the string value of the html input with the given name 
		\param name the name of the html input, this name needs to match the one given to the input
	*/
	std::string getString(std::string name);
};

#endif /* BB_CGI_H */