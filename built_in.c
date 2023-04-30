#include "shell.h"

/**
 * check_built- checks if function is a built in one
 * @cmd: command to check if exists
 * Return: 0 on success, 1 on failure
 */
int check_built(char *cmd)
{
	if (!strcmp(cmd, "env"))
	{
		env_imp();
		return (0);
	}
	else if (!strcmp(cmd, "exit"))
	{
		return (0);
	}
	return (1);
}

/**
 * env_imp- prints the invironment
 * Return: void
 */
void env_imp(void)
{
	int	i;

	if (environ)
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
}
