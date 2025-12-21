#include "main.h"

/**
 * main - blablabla
 * 
 */
int main(int ac, char **av, char **env)
{
	size_t len, arr_len, i;
	ssize_t nread;
	char *str_cpy, *token, *str;
	char **args;
	(void)av;
	(void)ac;

	while (1)
	{
		printf("$ ");
		nread = getline(&str, &len, stdin);
		if (nread == -1)
			break;
		token = strtok(str, "\n ");
		if (!token)
			continue;
		arr_len = 1;
		while (token)
		{
			token = strtok(NULL, "\n ");
			arr_len++;
		}
		str_cpy = strdup(str);
		free(str);
		args = malloc(sizeof(char *) * arr_len);
		if (!args)
			return (1);
		token = strtok(str_cpy, "\n ");
		i = 0;
		while (token)
		{
			args[i] = malloc(strlen(token) + 1);
			if (!args[i])
				return (1);
			args[i] = 
			token = strtok(NULL, "\n ");
			i++;
		}
		args[i] = NULL;
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
