#ifndef SHELL_PIPELINE_H
#define SHELL_PIPELINE_H

#include <vector>
class SimpleCommand;

/**
 * A pipeline, i.e. a set of simple commands of which the output of each previous
 * command is fed as the input to the next.
 * Note that you can have a pipeline with just a single command in which case it
 * is simply executed as is.
 */
class Pipeline {
	private:
		std::vector<SimpleCommand *> commands; //< The commands to execute
		bool async;                            //< True if this the sequence does not need to wait for the
		                                       //  pipeline to finish.

	public:
		Pipeline()
				: commands()
				, async(false)
		{}

		~Pipeline();

		bool isAsync() const    { return async; }
		void setAsync( bool b ) { async = b; }

		void addCommand( SimpleCommand *cmd ) { commands.push_back(cmd); }

		void execute();
};


#endif //SHELL_PIPELINE_H
