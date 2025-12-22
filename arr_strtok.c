#include "main.h"

/**
 * arr_strtok - Takes a string as input and returns an array of strings.
 * @str: Input string.
 * Return: An array of strings.
 */
char **arr_strtok(char *str)
{
	char *token;
	char **args;
	size_t i, arr_len;

	arr_len = strtok_arr_len(str);
	args = malloc(sizeof(char *) * arr_len);
	if (!args)
		return (NULL);
	token = strtok(str, "\n ");
	i = 0;
	while (token)
	{
		args[i] = malloc(strlen(token) + 1);
		if (!args[i])
		{
			while (i > 0)
			{
				i--;
				free(args[i]);
			}
			free(args);
			exit(1);
		}
		strcpy(args[i], token);
		token = strtok(NULL, "\n ");
		i++;
	}
	free(str);
	args[i] = NULL;
	return (args);
}
