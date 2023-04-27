#include "shell.h"

/**
 * main- runs the shell
 * @ac: amount of arguments
 * @av: list of arguments
 * @env: environment variables
 * Return: 0 on success, non-zero otherwise
 */
int main(int ac, char **av, char **env)
{
	int	mode, wstatus;
	char	**cmds = NULL;

	(void)ac;
	(void)av;
	(void)wstatus;
	(void)env;
	mode = isatty(STDIN_FILENO);
	do {
		if (mode)
			write(STDOUT_FILENO, "$ ", 2);
		cmds = cmd_to_arg();
		if (cmds)
		{
			if (check_builtin(cmds))
			{
				if (!access(cmds[0], F_OK))
				{
					if (!mode || ((fork()) ? (!wait(&wstatus)) : 1))
						execve(cmds[0], cmds, env);
				}
				else
					err_han(av[0], cmds[0]);
			}
			cmds = free_cmds(cmds);
		}
	} while (mode);
	cmds = free_cmds(cmds);
	return (0);
}
/**
 * check_builtin- checks if the command passed is a built in one
 * @cmds: commands
 * Return: 0 on succes, -1 otherwise
 */
int check_builtin(char **cmds)
{
	int val = -1;
	extern char **environ;

	if (strcmp(cmds[0], "exit") == 0)
		exit(0);
	if (strcmp(cmds[0], "env") == 0)
	{
		print_env(environ);
		val = 0;
	}
	return (val);
}
