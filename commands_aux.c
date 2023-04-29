#include "shell.h"

/**
 * free_args- frees args
 * @args: args to be freed
 * Return: void
 */
void free_args(char **args)
{
	int	i;

	if (args)
	{
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args[i]);
		free(args);
	}
}

/**
 * print_args- prints array of args
 * @args: array of args
 * Return: void
 */
void print_args(char **args)
{
	int	i;

	if (args)
		for (i = 0; args[i]; i++)
			printf("%s\n", args[i]);
}

