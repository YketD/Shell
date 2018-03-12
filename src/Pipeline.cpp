#include <iostream>
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
	std::cout << "FIXME: You should change Pipeline::execute()" << std::endl;

	for( SimpleCommand *cmd : commands ) {
		// FIXME: Probably need to set up some pipe here?

		cmd->execute();
	}
}