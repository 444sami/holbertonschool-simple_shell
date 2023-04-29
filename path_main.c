#include "shell.h"

/**
 * path_check- checks if path is valid
 * @cmdn: name of the command
 * Return: string if valid, NULL otherwise
 */
char *path_check(char *cmdn)
{
	int	len = 0, k, flag, f = 0;
	char	*pathname = NULL;

	if (!cmdn)
		return (NULL);
	while (cmdn[len])
		len++;
	if (cmdn[0] != '/')
	{
		pathname = malloc(sizeof(char) * (len + 2));
		if (!pathname)
			return (NULL);
		pathname[0] = '/';
		for (k = 0; k < len; k++)
			pathname[k + 1] = cmdn[k];
		pathname[k + 1] = '\0';
		f = 1;
	}
	else
		pathname = cmdn;
	printf("%s\n", pathname);
	flag = access(pathname, F_OK);
	if (flag)
	{
		if (f)
			free(pathname);
		return (NULL);
	}
	return (pathname);
}
