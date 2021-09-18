

#ifndef APT_H_DEF
#define APT_H_DEF

#include <string>

class apt
{
public:
	static int search (std::string);
	static int locate (std::string);
	static int install(std::string);
	static int remove (std::string);
	static std::string run_command(std::string);
};





#endif // !APT_H_DEF
