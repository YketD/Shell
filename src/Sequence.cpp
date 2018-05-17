#include <iostream>
#include <unistd.h>
#include "Sequence.h"
#include "Pipeline.h"

/**
 * Destructor.
 */
Sequence::~Sequence() {
	for( Pipeline *p : pipelines )
		delete p;
}

/**
 * Executes a sequence, i.e. runs all pipelines and - depending if the ampersand
 * was used - waits for execution to be finished or not.
 */
void Sequence::execute() {
	std::cout << "FIXME: You should change Sequence::execute()" << std::endl;

    pid_t pid;
	for( Pipeline *p : pipelines ) {
		// FIXME: More code needed?


        if (p->isAsync()) {
            pid = fork();
            if (pid == 0) { p->execute(); }
        }

		else p->execute();
	}
}
