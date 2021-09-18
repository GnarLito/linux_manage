#include "apt.h"


int apt::search(std::string name)
{
    std::string result = apt::run_command("apt search " + name);
    if (result.find(name) == -1)
    {
        return 1;
    }
    return 0;
}

int apt::locate(std::string name)
{
    std::string result = apt::run_command("dpkg -L "+ name);
    if (result.find("not installed") != -1) 
    {
        return 2;
    }
    return 0;
}

int apt::install(std::string name)
{
    std::string result = apt::run_command("sudo apt install -y "+ name);
    if (result.find("E: Unable to locate package") != -1)
    {
        return 3;
    }
    return 0;
}

int apt::remove(std::string name)
{
    std::string result = apt::run_command("sudo apt remove -y" + name);
    if (result.find("E: Unable to locate package") != -1)
    {
        return 3;
    }
    return 0;
}


std::string apt::run_command(std::string cmd)
{
    // run a system command, only run no validation.
    std::string data;
    FILE* stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
        pclose(stream);
    }
    return data;
}
