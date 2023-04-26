#include "shell.h"

/**
 * main- runs the shell
 * @ac: amount of arguments
 * @av: list of arguments
 * @environ: environment variables
 * Return: 0 on success, non-zero otherwise
 */
int main(int ac, char **av, char **environ)
{
	int	mode, wstatus;
	char	**cmds = NULL;

	(void)ac;
	(void)av;
	(void)wstatus;
	(void)environ;
	mode = isatty(STDIN_FILENO);
	do {
		if (mode)
			write(STDOUT_FILENO, "$ ", 2);
		cmds = cmd_to_arg();
		if (cmds)
		{
			if (strcmp(cmds[0], "exit") == 0)
				break;
			if (!access(cmds[0], F_OK))
			{
				if (!mode || ((fork()) ? (!wait(&wstatus)) : 1))
					execve(cmds[0], cmds, environ);
			}
			else
				err_han(av[0], cmds[0]);
			free_cmds(cmds);
		}
	} while (mode);
	free_cmds(cmds);
	return (0);
}
