#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include "SimpleCommand.h"

void SimpleCommand::execute() {
	std::cout << "FIXME: You should change SimpleCommand::execute()" << std::endl;
	// FIXME: Your code here...

    // create vector containing char to pass to exec call
    std::vector<char*> argsChr = {};
    argsChr.push_back(const_cast<char*>(command.c_str()));
    for(auto const &arg : arguments)
    {
        argsChr.emplace_back(const_cast<char*>(arg.c_str()));
    }
    argsChr.emplace_back(nullptr);

    // create fork of the process that will execute our command
    int pid = fork();
    if (pid == 0) {

        if (redirects.size() > 0)
        {
            //open(redirects[0].getNewFile());
        }

        execvp(command.c_str(), argsChr.data());
    }

    std::cout << "Redirects " << redirects.size() << std::endl;
}
