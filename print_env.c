#include "main.h"

/**
 * print_env - Prints the environment.
 * @env: Environment to pass into the children processes.
 * Return: 1 on error. 0 on success.
 */
void print_env(char **env)
{
	size_t i = 0;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
