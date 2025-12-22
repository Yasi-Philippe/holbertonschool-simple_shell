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
	int status;
	size_t i;

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
			perror("Error");
			exit(1);
		}
	}
	else
	{
		if(wait(&status) == -1)
			{
				i = 0;
				while (args[i])
				{
					free(args[i]);
					i++;
				}
				free(args);
				perror("Error");
				exit(1);
			}
	}
}
