#include "main.h"

/**
 * exit_shell - Function that handles the exit command.
 * @args: Array of command and its arguments.
 * @commands: Array of command lines.
 * @status: Int showing the status.
 * Return: void
 */
void exit_shell(char **args, char **commands, int status)
{
	free_args(args);
	free(commands);
	exit(status);
}
