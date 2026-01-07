#include "main.h"

/**
 * ev_exec_cmd - Shell Function. Evaluates commands and executes them.
 * @commands: Array of strings with the commands.
 * @env: Environment to pass into the children processes.
 * Return: Int of exit status.
 */
int ev_exec_cmd(char **commands, char **env, char **prg, int status)
{
	size_t i = 0;
	char **args = NULL;

	if (!commands)
		return (0);
	while (commands[i])
	{
		args = NULL;
		args = arr_strtok(commands[i], " \n");
		if (!args)
		{
			i++;
			continue;
		}
		if (!args[0])
		{
			i++;
			free_args(args);
			continue;
		}
		if (strcmp(args[0], "exit") == 0)
			exit_shell(args, commands, status);
		if (strcmp(args[0], "env") == 0)
		{
			print_env(env);
			free_args(args);
			i++;
			continue;
		}
		if (args[0][0] != '.' && args[0][0] != '/')
		{
			if (!find_path(args, env))
			{
				fprintf(stderr, "%s: %ld: %s: not found\n", prg[0], i + 1, args[0]);
				free_args(args);
				status = 127;
				return (status);
			}
			else
			{
				status = fork_shell(args, env);
				i++;
				continue;
			}
		}
		if (access(args[0], X_OK) != 0)
			{
				fprintf(stderr, "%s: %ld: %s: not found\n", prg[0], i + 1, args[0]);
				free_args(args);
				status = 127;
				return (status);
			}
		if (!args)
		{
			free_args(args);
			return (0);
		}
		status = fork_shell(args, env);
		i++;
	}
	return (0);
}
