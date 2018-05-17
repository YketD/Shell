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
	//std::cout << "FIXME: You should change Pipeline::execute()" << std::endl;

    if (commands.size() == 1)
    {
        commands[0]->execute();
    }
    else
    {
        // Create pipes
        auto pipeCount = static_cast<int>(commands.size() - 1);
        int pipes[2*pipeCount];
        for(unsigned int i = 0; i < pipeCount; i++)
        {
            if (pipe(pipes + i*2) < 0)
            {
                std::cout << "Piping failed" << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        int pid;
        unsigned int idx = 0;
        unsigned int j = 0;

        for (SimpleCommand *cmd : commands) {
            // FIXME: Probably need to set up some pipe here?

            pid = fork();
            if (pid == 0)  {
                // If not last command
                if (idx != (commands.size() - 1))
                {
                    if (dup2(pipes[j + 1], STDOUT_FILENO) < 0)
                    {
                        std::cout << "Dup2 out failed" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                }

                // If not first command
                if (idx != 0)
                {
                    if (dup2(pipes[j - 2], STDIN_FILENO) < 0)
                    {
                        std::cout << "Dup2 in failed" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                }

                for(unsigned int i = 0; i < 2*pipeCount; i++)
                    close(pipes[i]);

                cmd->execute();
            }

            idx++;
            j += 2;
        }

        for(unsigned int i = 0; i < 2*pipeCount; i++)
            close(pipes[i]);

        while (wait(NULL) > 0);
    }
}