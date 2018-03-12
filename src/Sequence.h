#ifndef SHELL_SEQUENCE_H
#define SHELL_SEQUENCE_H

#include <vector>

class Pipeline;

/**
 * Top-level class for an entered line in our shell.
 * Contains a list of pipelines to execute in order.
 */
class Sequence {
	private:
		std::vector<Pipeline *> pipelines;

	public:
		~Sequence();

		void addPipeline( Pipeline *pipeline ) {
			pipelines.push_back(pipeline);
		}

		void execute();
};


#endif //SHELL_SEQUENCE_H
