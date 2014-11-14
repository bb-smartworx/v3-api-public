//! B&B API Configuation class
/*!
	This class is used to load and save configuation settings for User Modules. 
	Settings are stored as key-value pairs
*/

#ifndef BB_CONFIG_H
#define BB_CONFIG_H

#include <json-c/json.h>
#include <string>

class BBConfig
{
private:
	std::string name; /*!< The name of the app  */
	std::string path; /*!< String to save the path and filename where settings are saved to and loaded from */
	json_object* obj; /*!< Json object to store the setting's key and value */

public:
	/** Integer identifier */
	static const int INT;
	/** String identifier */
	static const std::string STR;
	/** Boolean identifier */
	static const bool BOOL;
	/** Double identifier */
	static const double DOUBLE;

	//! Constructor for the configuation object
	/*!
		The constructor should be passed a string whose value is the path to the configuration file you wish to use and the name of the file, as well as the name of the application
		e.g /opt/APPNAME/etc/setting
		\param file the full path and the file name of the settings file
		\param appname the name of the application
	*/
	BBConfig(std::string file, std::string appname);

	// ~BBConfig();

	//! Load configuation file function
	/*!
		Loads configuation settings from the file specified in the path variable
		Saves it to the obj variable
	*/
	void load();

	//! Load configuation file function
	/*!
		Loads configuation settings from json_string.
		Saves it to the obj variable.
		\param json_string a json format string 
	*/
	void load(std::string json_string);

	//! Save configuation file function
	/*!
		Saves configuation settings in obj into the file specified in the path variable
	*/
	void save();

	//! Print configuation function
	/*!
		Prints the key value pairs to stdout.
		Used for debugging.
	*/
	void print();

	//! toString function
	/*!
		Returns a string with all the key-value pairs in it.
	*/
	std::string toString();

	//! Add new setting function
	/*!
		Adds a new key-value pair to the configuation object.
		\param key unique for each setting
		\param val value for the setting
	*/
	void addSetting(std::string key, int val);

	//! Add new setting function
	/*!
		Adds a new key-value pair to the configuation object.
		\param key unique for each setting
		\param val value for the setting
	*/
	void addSetting(std::string key, double val);

	//! Add new setting function
	/*!
		Adds a new key-value pair to the configuation object.
		\param key unique for each setting
		\param val value for the setting
	*/
	void addSetting(std::string key, bool val);
	
	//! Add new setting function
	/*!
		Adds a new key-value pair to the configuation object.
		\param key unique for each setting
		\param val value for the setting
	*/
	void addSetting(std::string key, const char* val);

	//! Remove setting function
	/*!
		Removes key-value pair from the configuation object.
		\param key unique for each setting
	*/
	void remSetting(std::string key);

	//! Get value setting function
	/*!
		Returns the value for the given key.
		\param key unique for each setting
		\param identifier identifier for return type; not used
	*/
	int getSetting(std::string key, int identifier);
	
	//! Get value setting function
	/*!
		Returns the value for the given key.
		\param key unique for each setting
		\param identifier identifier for return type; not used
	*/
	double getSetting(std::string key, double identifier);
	
	//! Get value setting function
	/*!
		Returns the value for the given key.
		\param key unique for each setting
		\param identifier identifier for return type; not used
	*/
	bool getSetting(std::string key, bool identifier);
	
	//! Get value setting function
	/*!
		Returns the value for the given key.
		\param key unique for each setting
		\param identifier identifier for return type; not used
	*/
	std::string getSetting(std::string key, std::string identifier);

	//! Set value setting function
	/*!
		Change the value associated with key to value.
		\param key unique for each setting
		\param val value for the setting
	*/
	void setSetting(std::string key, int val);

	//! Set value setting function
	/*!
		Change the value associated with key to value.
		\param key unique for each setting
		\param val value for the setting
	*/
	void setSetting(std::string key, double val);
	
	//! Set value setting function
	/*!
		Change the value associated with key to value.
		\param key unique for each setting
		\param val value for the setting
	*/
	void setSetting(std::string key, bool val);
	
	//! Set value setting function
	/*!
		Change the value associated with key to value.
		\param key unique for each setting
		\param val value for the setting
	*/
	void setSetting(std::string key, const char* val);
};

#endif /* BB_CONFIG_H */
