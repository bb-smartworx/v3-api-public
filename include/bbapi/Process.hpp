#include <string>
#include <sys/types.h>

class Process
{
private:
	std::string path_name;
	pid_t pID;

public:
	Process(std::string pn){path_name = pn; pID = 0;}

	std::string getname(){return path_name;}
	pid_t getpid(){return pID;}

	void setpid(pid_t p){pID = p;}
};