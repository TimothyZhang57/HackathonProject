#include "SSHClient.h"
#include <format>

int main(int argc, char *argv[])
{
    std::string my_string = std::format("this is a string with {} ", "Something");
    SSHClient ssh("qnxuser", "qnxuser", "192.168.122.126");
    ssh.connect();
    ssh.sendCommand("touch newtestfile");
    ssh.sendCommand(std::format("echo \"{}\" >> newtestfile", my_string));
}
