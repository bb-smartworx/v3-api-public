//! B&B API Process Manager class
/*!
	This class is used to run and manage external processes

*/

#ifndef BB_PROCESS_MANAGER_H
#define BB_PROCESS_MANAGER_H

#include <map>
#include <vector>
#include <string>

#include "Process.hpp"

class BBProcessManager
{
private:
	std::map<int, Process> running;

	void checkRunning();

public:
	BBProcessManager(){}
	~BBProcessManager(){}

	//! Start Process function
	/*!
		Starts the given process and waits for it to finish. Note: you must give the full path.
		\param name the name of the file and its path
		\param wait_exit flag to wait for the process to finish or run it in the backround
	*/
	void startProcess(std::string name, int wait_exit);
	
	//! Start Process function
	/*!
		Starts the given process with given parameters and waits for it to finish. Note: you must give the full path.
		\param name the name of the excutable and its path
		\param parameters a list of the parameters need for the excutable
		\param wait_exit flag to wait for the process to finish or run it in the backround
	*/
	void startProcess(std::string name, std::vector<std::string> parameters, int wait_exit);

	//! Stop Process function
	/*!
		Stops the given process.
		\param name the name of the process running
		\param option flag to determine with instance of a process to stop. 0 for all processes with the given name, 1 for the first, 2 for the second ...etc.
	*/
	void stopProcess(std::string name, int option);

	//! Restart Process function
	/*!
		Restarts the given process.
		\param name the name of the process you wish to restart
		\param wait_exit flag to wait for the process to finish or run it in the backround
	*/
	void restartProcess(std::string name, int wait_exit);

	//! Restart Process function
	/*
		Restarts the given process with the given parameters
		\param name the name of the excutable and its path
		\param parameters a list of the parameters need for the excutable
		\param wait_exit flag to wait for the process to finish or run it in the backround
	*/
	void restartProcess(std::string name, std::vector<std::string> parameters, int wait_exit);
};

#endif /* BB_PROCESS_MANAGER_H */