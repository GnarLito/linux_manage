

#ifndef main_h_def
#define main_h_def

#include <cstdio>
#include <vector>
#include <string>

#include "apt.h"


std::vector<std::string> args;


void load_args(int, char**);

int install(std::string);
int remove(std::string);


enum types
{
	install
	, remove
};
types to_type(std::string);


#endif // !main_h_defs