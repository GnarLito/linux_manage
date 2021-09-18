#include "main.h"


int main(int argc, char** argv)
{
    load_args(argc, argv);

    if (args.size() > 0)
    {
        switch (to_type(args[1]))
        {
        case types::install:
            return install(args[2]);

        case types::remove:
            return remove(args[2]);
        default:
            break;
        }
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
    int result = apt::search(name);
    if (result != 0) return result;

    result = apt::locate(name);
    if (result != 0) return result;
    
    result = apt::install(name);
    if (result != 0) return result;
    
    return 0;
}
int remove(std::string name)
{
    int result = apt::locate(name);
    if (result != 0) return result;

    result = apt::remove(name);
    if (result != 0) return result;

    return 0;
}


types to_type(std::string type)
{
    if (type == "install") { return types::install; }
    if (type == "remove")  { return types::remove;  }
}