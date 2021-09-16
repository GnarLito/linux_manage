#include "main.h"



int main(int argc, char** argv)
{
    load_args(argc, argv);

    if (args.size() > 0 && args[1] == "install")
    {
        return install(args[2]);
    }

    return 0;
}



void load_args(int argc, char** argv)
{
    for (int i = 0; i < argc; i++) {
        args.push_back(argv[i]);
    }
}


int install(std::string name)
{
    apt_search();
    apt_locate();
    apt_install();

}