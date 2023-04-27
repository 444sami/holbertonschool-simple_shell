#include "shell.h"

/**
 * exit- exits the shell
 * @val: exit value
 * Retrurn: void
 */
void exit(int val)
{
	_exit(val);
}

/**
 * print_env- prints the current environment
 * @env: current environmet
 * Return: always 0
 */
void print_env(char **env)
{
	int	i;

	for (i = 0; env[i]; i++)
		printf("%s\n", env[i]);
}
