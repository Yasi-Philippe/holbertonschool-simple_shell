#include "main.h"

/**
 * _exit - Function that handles the exit command.
 * @args: Array of command and its arguments.
 * Return: void
 */
void _exit(char **args)
{
	free_args(args);
	exit(0);
}
