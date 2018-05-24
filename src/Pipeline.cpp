#include <iostream>
#include <unistd.h>
#include <wait.h>
#include "Pipeline.h"
#include "SimpleCommand.h"

/**
 * Destructor.
 */
Pipeline::~Pipeline() {
	for( SimpleCommand *cmd : commands )
		delete cmd;
}

/**
 * Executes the commands on this pipeline.
 */
void Pipeline::execute() {
    //check if a pipe is needed
    if (commands.size() == 1)
    {
        commands[0]->execute();
    }
    else
    {
        // check how many pipes are needed
        auto pipeCount = static_cast<int>(commands.size() - 1);

        //create pipes array
        int pipes[2*pipeCount];

        //creating pipes & writing to pipes array
        for(unsigned int i = 0; i < pipeCount; i++)
        {
            if (pipe(pipes + i*2) < 0)
            {
                std::cout << "Piping failed" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        /* -- VARIABLE DECLARATION --
            pid = system process id
            idx = command id
            j   = pipe id
        */
        int pid;
        unsigned int idx = 0;
        unsigned int j = 0;

        // Iterate through commands
        for (SimpleCommand *cmd : commands) {

            // Fork process & save process id of current process
            pid = fork();

            // in case of child process
            if (pid == 0)  {
                // If not last command, write output to next command
                if (idx != (commands.size() - 1))
                {
                    if (dup2(pipes[j + 1], STDOUT_FILENO) < 0)
                    {
                        std::cout << "Dup2 out failed" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                }

                // If not first command, read input from last command
                if (idx != 0)
                {
                    if (dup2(pipes[j - 2], STDIN_FILENO) < 0)
                    {
                        std::cout << "Dup2 in failed" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                }

                //close all pipes in pipe array
                for(unsigned int i = 0; i < 2*pipeCount; i++)
                    close(pipes[i]);

                //execute the command
                cmd->execute();
                exit(EXIT_SUCCESS);
            }
            /* -- UP ITERATORS --
             command index incremented by 1 (next command)
             pipe incremented by 2 (2 spaces in array : [in,out])
             */
            idx++;
            j += 2;
        }
        // close all pipes
        for(unsigned int i = 0; i < 2*pipeCount; i++)
            close(pipes[i]);

        // Wait for execution to finish
        while (wait(nullptr) > 0)
        {}
    }
}