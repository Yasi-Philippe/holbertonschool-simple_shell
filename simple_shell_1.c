#include "main.h"

/**
 * main - Shell Function. Takes commands as input and execcute the programs
 * linked to these commands.
 * @ac: Number of arguments provided (Void)
 * @av: Array with the arguments provided (Void)
 * @env: Environment to pass into the children processes.
 * Return: 1 on error. 0 on success.
 */
int main(int ac, char **av, char **env)
{
	size_t len;
	ssize_t nread;
	char *str;
	char **commands;
	int interactive;
	(void)av;
	(void)ac;

	interactive = isatty(STDIN_FILENO);
	while (1)
	{
		if (interactive)
			printf("$ ");
		str = NULL;
		commands = NULL;
		nread = getline(&str, &len, stdin);
		if (nread == -1)
		{
			if (interactive)
				printf("\n");
			break;
		}
		commands = arr_strtok(str, "\n");
		simple_shell_2(commands, env);
		free(commands);
	}
	free(str);
	return (0);
}
