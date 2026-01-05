#include "main.h"

/**
 * exit_shell - Function that handles the exit command.
 * @args: Array of command and its arguments.
 * Return: void
 */
void exit_shell(char **args)
{
	free_args(args);
	exit(0);
}
