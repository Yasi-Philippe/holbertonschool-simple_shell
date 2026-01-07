#include "main.h"

/**
 * err_not_found - Prints error not found.
 * @prg: Name of the Shell program.
 * @i: Number of command.
 * @args: Array containing arguments of function.
 * @status: Int of the status.
 */
void err_not_found(char **prg, size_t i, char **args, int *status)
{
	fprintf(stderr, "%s: %ld: %s: not found\n", prg[0], i + 1, args[0]);
	free_args(args);
	*status = 127;
}

/**
 * pre_ev - Shell Function. Pre-evaluates the command.
 * @commands: Array of strings with the commands.
 * @env: Environment to pass into the children processes.
 * @status: Int of the status.
 * @args: Array containing the arguments of the command.
 * Return: 1 if env has been printed. 0 if not.
 */
int pre_ev(char **commands, char **env, int status, char **args)
{
	if (strcmp(args[0], "exit") == 0)
		exit_shell(args, commands, status);
	if (strcmp(args[0], "env") == 0)
	{
		print_env(env);
		free_args(args);
		return (1);
	}
	return (0);
}



/**
 * pre_exec - Shell Function. Last check before execution.
 * @args: Array of strings with the commands.
 * @prg: Arguments of the user.
 * @i: Number of the command.
 * @status: Status error of the program.
 * Return: 1 if program is not executable. 0 SUccess.
 */
int pre_exec(char **args, char **prg, size_t i, int *status)
{
	if (access(args[0], X_OK) != 0)
	{
		err_not_found(prg, i, args, status);
		return (1);
	}
	if (!args)
	{
		free_args(args);
		return (1);
	}
	return (0);
}

/**
 * ev_exec_cmd - Shell Function. Evaluates commands and executes them.
 * @commands: Array of strings with the commands.
 * @env: Environment to pass into the children processes.
 * @prg: Arguments typed by the user.
 * @status: Staus of the program.
 * Return: Int of exit status.
 */
int ev_exec_cmd(char **commands, char **env, char **prg, int status)
{
	size_t i = 0;
	char **args = NULL;

	if (!commands)
		return (status);
	while (commands[i])
	{
		args = arr_strtok(commands[i], " \n");
		if (!args)
			return (1);
		if (!args[0])
		{
			free_args(args);
			return (1);
		}
		if (pre_ev(commands, env, status, args))
		{
			i++;
			continue;
		}
		if (args[0][0] != '.' && args[0][0] != '/')
		{
			if (!find_path(args, env))
			{
				err_not_found(prg, i, args, &status);
				return (status);
			}
			else
			{
				status = fork_shell(args, env);
				i++;
				continue;
			}
		}
		if (pre_exec(args, prg, i, &status))
			return (status);
		status = fork_shell(args, env);
		i++;
	}
	return (status);
}
