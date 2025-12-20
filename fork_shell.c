#include "main.h"

/**
 * fork_shell - blablabla
 * 
 */

void fork_shell(char *args[], char **env)
{
	pid_t child_pid;
	int status;

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
		wait(&status);
	}
}
