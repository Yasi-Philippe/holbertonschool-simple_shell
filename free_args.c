#include "main.h"

/**
 * free_args - Function that frees a 2D array of strings.
 * @args: 2D array of strings to be freed.
 */
void free_args(char **args)
{
	size_t i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
