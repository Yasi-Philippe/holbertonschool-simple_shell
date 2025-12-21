#include "main.h"

/**
 * main - blablabla
 * 
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
		printf("$ ");
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
		free(args[i]);
		free(args);
	}
	return (0);
}
