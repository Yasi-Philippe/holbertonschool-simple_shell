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
	char *token_2;
	char *my_path;
	char *my_path_2;

	while (env[i])
	{
		if (strncmp(env[i], "PATH", 4) == 0)
		{
			token = strtok(env[i], "=");
			token = strtok(NULL, "=");
			token_2 = strtok(token, ":");
			while (token_2)
			{
				my_path = strcat(token_2, "/");
				my_path_2 = strcat(my_path, args[0]);
				if (access(my_path_2, X_OK) == 0)
				{
					free(args[0]);
					args[0] = malloc(strlen(my_path_2) + 1);
					strcpy(args[0], my_path_2);
					return (args);
				}
				token_2 = strtok(NULL, ":");
			}
		}
		i++;
	}
	return (NULL);
}
