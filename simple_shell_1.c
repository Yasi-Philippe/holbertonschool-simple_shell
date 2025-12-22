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
	size_t len, i;
	ssize_t nread;
	char *str;
	char **args;
	(void)av;
	(void)ac;

	while (1)
	{
		str = NULL;
		nread = getline(&str, &len, stdin);
		if (nread == -1)
			break;
		if (nread == 1 && *str == '\n')
			continue;
		args = arr_strtok(str);
		if (!args)
			return (1);
		fork_shell(args, env);
		i = 0;
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
	return (0);
}
