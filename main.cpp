#include "main.h"


int main(int argc, char** argv)
{
    load_args(argc, argv);
    
    int result = -1;
    if (args.size() > 2)
    {
        switch (to_type(args[1]))
        {
        case types::install_arg:
            result = apt_install(args[2]);

        case types::remove_arg:
            result = apt_remove(args[2]);
        default:
            break;
        }
    }
    else
    {
        std::printf("u need to give more parameters");
        return 1;
    }

    switch (result)
    {
    case 0:
        std::printf("Success\n"); 
        break;
    default:
        std::printf("failed Status: "+ result);
        std::printf("\n");
        break;
    }


    return 0;
}


void load_args(int argc, char** argv)
{
    for (int i = 0; i < argc; i++) {
        args.push_back(argv[i]);
    }
}


int apt_install(std::string name)
{
    int result = apt::search(name);
    if (result != 0) return result;

    result = apt::locate(name);
    if (result != 0) return result;
    
    result = apt::install(name);
    if (result != 0) return result;
    
    return 0;
}
int apt_remove(std::string name)
{
    int result = apt::locate(name);
    if (result != 0) return result;

    result = apt::remove(name);
    if (result != 0) return result;

    return 0;
}


types to_type(std::string type)
{
    if      (type == "install") { return types::install_arg; }
    else if (type == "remove")  { return types::remove_arg;  }
    else    { return types::None_arg; }
}