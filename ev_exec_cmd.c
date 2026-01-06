#include "main.h"

/**
 * ev_exec_cmd - Shell Function. Evaluates commands and executes them.
 * @commands: Array of strings with the commands.
 * @env: Environment to pass into the children processes.
 */
void ev_exec_cmd(char **commands, char **env)
{
	size_t i = 0;
	char **args = NULL;

	while (commands[i])
	{
		args = arr_strtok(commands[i], " ");
		if (!args)
			return;
		if (strcmp(args[0], "exit") == 0)
			exit_shell(args, commands);
		if (strcmp(args[0], "env") == 0)
		{
			print_env(env);
			free_args(args);
			return;
		}
		if (access(args[0], X_OK) != 0)
		{
			if (!find_path(args, env))
			{
				perror("Error");
				free_args(args);
				return;
			}
		}
		if (!args)
		{
			free_args(args);
			return;
		}
		fork_shell(args, env);
		i++;
	}
}
