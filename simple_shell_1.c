#include "main.h"

/**
 * main - Shell Function. Takes commands as input and execcute the programs
 * linked to these commands.
 * @ac: Number of arguments provided (Void)
 * @av: Array with the arguments provided (Void)
 * @env: Environment to pass into the children processes.
 * Return: 1 on error. 0 on success.
 */
int main(int ac, char **av, char **env)
{
	size_t len;
	ssize_t nread;
	char *str;
	char **args;
	(void)av;
	(void)ac;

	while (1)
	{
		str = NULL;
		args = NULL;
		nread = getline(&str, &len, stdin);
		if (nread == -1)
			break;
		args = arr_strtok(str);
		if (!args)
			continue;
		if (access(args[0], X_OK) != 0)
		{
			if (!find_path(args, env))
			{
				perror("Error");
				free_args(args);
				continue;
			}
		}
		if (!args)
		{
			free_args(args);
			continue;
		}
		fork_shell(args, env);
		free_args(args);
	}
	free(str);
	return (0);
}
