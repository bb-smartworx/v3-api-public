//! B&B API HTML Builder class
/*!
	This class is used to create HTML pages to interface with User Modules.
	Lets you add various input boxes to create and save settings for the module.
*/

#ifndef BB_HTML_H
#define BB_HTML_H

#include <vector>
#include <string>

class BBHtml
{
private:
	int num_rows;
	bool form_started;

	void startCell();
	void endCell();
	void startForm();
	void endForm(); 

public:
	BBHtml()
	{
		num_rows = 0;
		form_started = false;
	}
	~BBHtml(){}

	//! Start function
	/*!
		Creates the header for the html. Should be the first function you call once you create the BBHtml object
		\param appname string for the name of the user module
	*/
	void pageBegin(std::string appname);

	//! Stop function
	/*!
		Creates the tail for the html. Should be the last function you call.
	*/
	void pageEnd();

	//! Add text function
	/*!	
		Adds the given text string to the web page
		\param text string for the text 
	*/
	void addText(std::string text);

	//! Add TextField function
	/*!
		Adds a textfield to the webpage for entering text
		\param text string for the text beside the testfield
		\param name a name for the textfield
		\param value the current value of the setting from the configuation file
	*/
	void addTextField(std::string text, std::string name, std::string value);

	//! Add TextField function
	/*!
		Adds a textfield to the webpage for entering text
		\param text string for the text beside the testfield
		\param name a name for the textfield
		\param value the current value of the setting from the configuation file
	*/
	void addTextField(std::string text, std::string name, int value);

	//! Add PassField function
	/*!
		Adds a textfield to the webpage for entering passwords, test in the field appears as circles or stars.
		\param text string for the text beside the passfield
		\param name a name for the textfield
		\param value the current value of the setting from the configuation file
	*/
	void addPassField(std::string text, std::string name, std::string value);

	//! Add Checkbox function
	/*!
		Adds a checkbox to the webpage for enable/disable input
		\param text string for the text beside the checkbox
		\param name a name for the textfield
		\param value the current value of the setting from the configuation file
	*/
	void addCheckbox(std::string text, std::string name, bool value);

	//! Add Submit Button function
	/*!
		Adds a submit button to the webpage for saving the settings entered
		\param name a name for the textfield
	*/
	void addSubmitButton(std::string name);

	//! Add Line Break function
	/*
		Adds a line between two inputs to separate two groups of settings
	*/
	void addLineBreak();

	//! Add Drop-Down Menu function
	/*
		Adds a drop-down menu list
		\param text string for the text beside the list
		\name a name for the list
		\param value the current value of the setting from the configuation file
		\param options a map of key-value pairs that will make up the drop-down list
	*/
	void addDropDown(std::string text, std::string name, std::string value, std::vector< std::pair<std::string, std::string> > options);

	//! Add Drop-Down Menu function
	/*
		Adds a drop-down menu list
		\param text string for the text beside the list
		\name a name for the list
		\param value the current value of the setting from the configuation file
		\param options a map of key-value pairs that will make up the drop-down list
	*/
	void addDropDown(std::string text, std::string name, int value, std::vector< std::pair<std::string, int> > options);
};

#endif /* BB_HTML_H */