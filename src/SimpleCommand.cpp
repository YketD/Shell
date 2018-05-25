#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#include <sys/stat.h>
#include "SimpleCommand.h"

void SimpleCommand::execute() {

    // Better way to exit
    if (command == "exit")
    {
        exit(0);
    }
    // Change directory
    else if (command == "cd")
    {
        if (arguments.empty())
        {
            chdir(getenv("HOME"));
        }
        else
        {
            // check if goal = ~ + "/anything"
            //if so, change current dir to home dir /anything
            if (arguments[0][0] == '~')
            {

                arguments[0].erase(0, 1);
                arguments[0] = getenv("HOME") + arguments[0];
            }

            // Directory handling
            // Checking first if dir exists, second if you have permissions to read
            struct stat st;
            if ((stat(arguments[0].c_str(), &st) != 0) || (((st.st_mode) & S_IFMT) != S_IFDIR))
                std::cerr << "Not a valid directory" << std::endl;
            else if (access(arguments[0].c_str(), R_OK) != 0)
                std::cerr << "Not a valid directory or insufficient permissions" << std::endl;
            else
                chdir((char *) arguments[0].c_str());
        }
    }
    else
    {

        //to execute execvp, 2 arguments are needed
        //1. <char *>array
        //  a "string" containing the command
        //2. <char *>vector
        //  which contains
        //      1. the command
        //      2. the argument list
        //      3. a nullptr

        // create & fill 2. of description above
        std::vector<char *> argsChr = {};
        argsChr.push_back(const_cast<char *>(command.c_str()));
        for (auto const &arg : arguments)
        {
            argsChr.emplace_back(const_cast<char *>(arg.c_str()));
        }
        argsChr.emplace_back(nullptr);

		//var declaration
        pid_t pid;
        int status;

        //fork, if succesfull & child process, execvp
        //if succesfull & parent process, wait for child to finish
        if ((pid = fork()) < 0) {
            std::cerr << "Forking child failed" << std::endl;
        } else if (pid == 0) {
             // Redirects

             /*
              * Var Dec
              * fd = file descriptor
              * flags = purpose for opening file (write, read)
              */
            int fd = -1;
            int flags = O_CREAT;

            //iterate through redirects
            for (const IORedirect &redirect : redirects)
            {
                //check goal of opening the file
                // write    ".. >  /file"
                // read     ".. <  /file"
                // append   ".. >> /file"
                if (redirect.getType() == IORedirect::Type::INPUT)
                    flags = flags | O_RDONLY;
                else if (redirect.getType() == IORedirect::Type::OUTPUT)
                    flags = flags | O_WRONLY;
                else if (redirect.getType() == IORedirect::Type::APPEND)
                    flags = flags | O_WRONLY | O_APPEND;

                //open file & save descriptor in fd
                //check for succesfull creation before continuing
                if ((fd = open(redirect.getNewFile().c_str(), flags)))
                {
                    //close the unnecessary connections to the files
                    if (redirect.getType() == IORedirect::Type::INPUT)
                        close(STDIN_FILENO);
                    else if (redirect.getType() == IORedirect::Type::OUTPUT)
                        close(STDOUT_FILENO);
                    else if (redirect.getType() == IORedirect::Type::APPEND)
                        close(STDOUT_FILENO);

                    //duplicate socket & assign new input/output connection to file
                    dup(fd);
                    //close old socket
                    close(fd);
                }
            }

            if (execvp(command.c_str(), argsChr.data()) < 0){
                std::cout << "Executing failed" << std::endl;
            }

        }
        else
        {
            // wait for child to finish execution
            while (wait(&status) != pid)
            {}
        }
    }
}
