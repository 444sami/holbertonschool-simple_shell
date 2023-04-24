#include "shell.h"

#include <stdio.h>
#include <string.h>

/**
 * main- runs the shell
 * @ac: amount of arguments
 * @av: list of arguments
 * @env: environment variables
 * Return: 0 on success, non-zero otherwise
 */
int main(int ac, char**av, char **env)
{
	if (ac == 1)
		interactive_mode(1, 0, NULL, env);
	else
		interactive_mode(0, ac , &(av[1]), env);
	return (0);
}

/**
 * interactive_mode- activates the interactive mode
 * @mode: indicates if the mode is interactive or one run only
 * @ac: amount of arguments for non interactive mode
 * @av: list of arguments for non interactive mode
 * @env: encironment variables
 * Return: void
 */
void interactive_mode(int mode, int ac, char **av, char **env)
{
	char **cmds= NULL;

	do {
		write(1, "$ ", 2);
		cmds = (mode) ? cmd_to_arg() : av;
		if (strcmp(cmds[0], "exit") == 0)
			break;
	} while (mode);
}
