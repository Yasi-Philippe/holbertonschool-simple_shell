#include "main.h"

/**
 * main - blablabla
 * 
 */
int main(int ac, char **av, char **env)
{
	size_t len;
	ssize_t nread;
	char *str;
	pid_t child_pid;
	char *args;
	int status;
	
	while (1)
	{
		printf("$ ");
		nread = getline(&str, &len, stdin);

		if (nread == -1)
		{
			break;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			free(str);
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			args = malloc(sizeof)
			if (execve(&str, args, env) == -1)
			{
				free(str);
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
			free(str);
		}
	}
	free(str);
	return (0);
}
