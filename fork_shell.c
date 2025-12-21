#include "main.h"

/**
 * fork_shell - Function that forks the main processus into a child and
 * executes the program linked to the comand given in the child processus.
 * @args: Array of strings containing the input words.
 * @env: ENvironment.
 */

void fork_shell(char *args[], char **env)
{
	pid_t child_pid;
	int status, i = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			while (args[i])
			{
				free(args[i]);
				i++;
			}
			free(args[i]);
			free(args);
			perror("Error");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}
