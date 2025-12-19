#include "main.h"

/**
 * main - blablabla
 * 
 */
int main(int ac, char **av, char **env)
{
	size_t len;
	size_t arr_len = 1;
	ssize_t nread;
	char *str, *str_cpy;
	char **args;
	char *token;
	(void)av;
	(void)ac;

	while (1)
	{
		printf("$ ");
		nread = getline(&str, &len, stdin);
		str_cpy = strdup(str);
		token = strtok(str, "\n \t");
		if (nread == -1)
			break;
		if (!token)
			continue;
		args = malloc(sizeof(char *) * arr_len)
	}
	free(str);
	return (0);
}
