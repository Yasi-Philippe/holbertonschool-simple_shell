#include "main.h"

/**
 * arr_strtok - Takes a string as input and returns an array of strings.
 * @str: Input string.
 * Return: An array of strings.
 */
char **arr_strtok(char *str)
{
	char *token, *str_cpy;
	char **args;
	size_t i, arr_len;

	str_cpy = strdup(str);
	if (!str_cpy)
	{
		free(str);
		exit(1);
	}
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
		{
			while(i > 0)
			{
				i--;
				free (args[i]);
			}
			free(args[i]);
			free(args);
			exit(1);
		}
		strcpy(args[i], token);
		token = strtok(NULL, "\n ");
		i++;
	}
	free(str_cpy);
	args[i] = NULL;
	return (args);
}
