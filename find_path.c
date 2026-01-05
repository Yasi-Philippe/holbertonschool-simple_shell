#include "main.h"

/**
 * find_path - Function that finds the full path of a command.
 * @args: Array of command and its arguments.
 * @env: Environment variables.
 * Return: Full path of the command, or NULL if not found.
 */
char **find_path(char *args[], char **env)
{
	size_t i = 0;
	char *token;
	char *my_path;
	char *path_copy;

	if (!env)
	{
		return (NULL);
	}
	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path_copy = malloc(sizeof(char) * (strlen(env[i]) + 1));
			strcpy(path_copy, env[i]);
			token = strtok(path_copy, "=");
			token = strtok(NULL, ":");
			if (!token)
			{
				free(path_copy);
				return (NULL);
			}
			while (token)
			{
				my_path = malloc(sizeof(char) * (strlen(token) + strlen(args[0]) + 2));
				sprintf(my_path, "%s/%s", token, args[0]);
				if (access(my_path, X_OK) == 0)
				{
					free(args[0]);
					args[0] = malloc(strlen(my_path) + 1);
					strcpy(args[0], my_path);
					free(my_path);
					free(path_copy);
					return (args);
				}
				token = strtok(NULL, ":");
				free(my_path);
			}
			free(path_copy);
		}
		i++;
	}
	return (NULL);
}
