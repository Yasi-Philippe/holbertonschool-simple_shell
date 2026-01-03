#include "main.h"

/**
 * arr_strtok - Takes a string as input and returns an array of strings.
 * @str: Input string.
 * @separator: Character to split the string.
 * Return: An array of strings.
 */
char **arr_strtok(char *str, char *separator)
{
	char *token;
	char **args;
	size_t i, arr_len;

	arr_len = strtok_arr_len(str);
	if (arr_len == 1)
	{
		free(str);
		return (NULL);
	}
	args = malloc(sizeof(char *) * arr_len);
	if (!args)
	{
		free(str);
		exit(1);
	}
	token = strtok(str, separator);
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
		token = strtok(NULL, separator);
		i++;
	}
	free(str);
	args[i] = NULL;
	return (args);
}
