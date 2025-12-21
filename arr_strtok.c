#include "main.h"

/**
 * main - blablabla
 * 
 */
char **arr_strtok(char *str)
{
	char *token, *str_cpy;
	char **args;
	size_t i, arr_len;

	str_cpy = strdup(str);
	if (!str_cpy)
		exit(1);
	token = strtok(str, "\n ");
	arr_len = 1;
	while (token)
	{
		token = strtok(NULL, "\n ");
		arr_len++;
	}
	free(str);
	args = malloc(sizeof(char *) * arr_len);
	if (!args)
		return (NULL);
	token = strtok(str_cpy, "\n ");
	i = 0;
	while (token)
	{
		args[i] = malloc(strlen(token) + 1);
		if (!args[i])
			return (NULL);
		strcpy(args[i], token);
		token = strtok(NULL, "\n ");
		i++;
	}
	free(str_cpy);
	args[i] = NULL;
	return(args);
}
