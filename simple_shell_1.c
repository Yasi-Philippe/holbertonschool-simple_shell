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
	size_t len, i = 0;
	ssize_t nread;
	char *str;
	char **args, **commands;
	(void)av;
	(void)ac;


	while (1)
	{
		str = NULL;
		args = NULL;
		nread = getline(&str, &len, stdin);
		if (nread == -1)
			break;
<<<<<<< HEAD
		commands = arr_strtok(str, "\n");
		while (commands[i])
=======
		args = arr_strtok(str);
		if (!args)
			continue;
		if (strcmp(args[0], "exit") == 0)
		  exit_shell(args);
		if (access(args[0], X_OK) != 0)
>>>>>>> f2f82da5daa1d7f710d002f39f687d37e46dcbb2
		{
			args = arr_strtok(commands[i], " ");
			if (!args)
				continue;
			if (strcmp(args[0], "exit") == 0)
				exit_shell(args);
			if (access(args[0], X_OK) != 0)
			{
				if (!find_path(args, env))
				{
					perror("Error");
					free_args(args);
					continue;
				}
			}
			if (!args)
			{
				free_args(args);
				continue;
			}
			fork_shell(args, env);
			free_args(args);
			i++;
		}
		i = 0;
	}
	free_args(commands);
	return (0);
}
