#include "main.h"



int main(int argc, char** argv)
{
    load_args(argc, argv);


    return 0;
}



void load_args(int argc, char** argv)
{
    for (int i = 0; i < argc; i++) {
        args.push_back(argv[i]);
    }
}