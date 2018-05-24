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

    int pid;
    
    // Execute each pipeline
    for( Pipeline *p : pipelines )
    {
        if (p->isAsync())
        {
            // Execute in a child if async
            if ((pid = fork()) == 0)
                p->execute();
        }

        // Else just execute normally
        else
        {
            p->execute();
        }
    }
}
