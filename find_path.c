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
			printf("%s\n", env[i]);
			token = strtok(env[i], "=");
			printf("%s\n", token);
			token = strtok(NULL, "=");
			printf("%s\n", token);
			token_2 = strtok(token, ":");
			printf("Test1\n%s", token_2);
			while (token_2)
			{
				printf("Test1\n%s", token_2);
				my_path = strcat(token_2, "/");
				my_path_2 = strcat(my_path, args[0]);
				printf("Test2\n");
				if (access(my_path_2, X_OK) == 0)
				{
					printf("Test3\n");
					free(args[0]);
					printf("Test4\n");
					args[0] = malloc(strlen(my_path_2) + 1);
					printf("Test5\n");
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
