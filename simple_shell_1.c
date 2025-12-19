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
	char *args[2];
	int status;
	char *token;
	(void)av;
	(void)ac;

	while (1)
	{
		printf("$ ");
		nread = getline(&str, &len, stdin);
		token = strtok(str, "\n");
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
			args[0] = token;
			args[1] = NULL;
			if (execve(token, args, env) == -1)
			{
				perror("Error:");
				return(1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(str);
	return (0);
}
