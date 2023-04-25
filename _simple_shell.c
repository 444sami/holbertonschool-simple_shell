#include "shell.h"

/**
 * main- runs the shell
 * @ac: amount of arguments
 * @av: list of arguments
 * @env: environment variables
 * Return: 0 on success, non-zero otherwise
 */
int main(void)
{
	int	mode, wstatus;
	char	**cmds = NULL;
	extern char **environ;

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
				printf("./shell: %s: No such file or directory\n", cmds[0]);
		}
	} while (mode);
	return (0);
}
