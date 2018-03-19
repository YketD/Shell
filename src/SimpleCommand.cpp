#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include "SimpleCommand.h"

void SimpleCommand::execute() {
	//std::cout << "FIXME: You should change SimpleCommand::execute()" << std::endl;

    // Change directory
    if (command.compare("cd") == 0)
    {
        if (arguments.empty())
            chdir(getenv("HOME"));
        else
            chdir((char*) arguments[0].c_str());

        exit(EXIT_SUCCESS);
    }

    // Redirects
    int fd = -1;
    int flags = O_CREAT;
    for (const IORedirect &redirect : redirects)
    {
        if (redirect.getType() == IORedirect::Type::INPUT)
            flags = flags | O_RDONLY;
        else if (redirect.getType() == IORedirect::Type::OUTPUT)
            flags = flags | O_WRONLY;
        else if (redirect.getType() == IORedirect::Type::APPEND)
            flags = flags | O_WRONLY | O_APPEND;

        if ((fd = open(redirect.getNewFile().c_str(), flags)))
        {
            if (redirect.getType() == IORedirect::Type::INPUT)
                close(STDIN_FILENO);
            else if (redirect.getType() == IORedirect::Type::OUTPUT)
                close(STDOUT_FILENO);
            else if (redirect.getType() == IORedirect::Type::APPEND)
                close(STDOUT_FILENO);

            dup(fd);
            close(fd);
        }
    }

    // create vector containing char to pass to exec call
    std::vector<char *> argsChr = {};
    argsChr.push_back(const_cast<char *>(command.c_str()));
    for (auto const &arg : arguments)
    {
        argsChr.emplace_back(const_cast<char *>(arg.c_str()));
    }
    argsChr.emplace_back(nullptr);

    int forkResult = execvp(command.c_str(), argsChr.data());
    if (forkResult < 0)
    {
        std::cout << "Executing failed" << std::endl;
        exit(EXIT_FAILURE);
    }
}
