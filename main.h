

#ifndef main_h_def
#define main_h_def

#include <cstdio>
#include <vector>
#include <string>

#include "apt.h"


std::vector<std::string> args;


void load_args(int, char**);

int apt_install(std::string);
int apt_remove(std::string);


enum types
{
	install_arg,
	remove_arg,
	None_arg
};
types to_type(std::string);


#endif // !main_h_defs