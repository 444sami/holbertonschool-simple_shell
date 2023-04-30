#include "shell.h"

/**
 * path_remake- tries all possible pathnames possibles
 * @list: list to check and change if necessary
 * Return: a str with the full pathname if exists, NULL otherwise
 */
void path_remake(l_node *list)
{
	int	len = 0, i;
	char	*str = NULL, *path = NULL;
	l_node	*aux = NULL;

	if (list)
	{
		aux = list;
		while (aux)
		{
			if (aux->str[0] != '/')
			{
				while (aux->str[len])
					len++;
				str = malloc(sizeof(char) * (len + 2));
				if (str)
				{
					str[0] = '/';
					for (i = 0; i < len; i++)
						str[i + 1] = aux->str[i];
					str[i + 1] = '\0';
					path = path_uni(str);
					if (path)
					{
						free(aux->str);
						aux->str = path;
					}
				}
				free(str);
				str = NULL;
			}
			aux = aux->next;
		}
	}
}

/**
 * path_uni- tries possibles pathes
 * @str: command name
 * Return: full path if successful, NULL otherwise
 */
char *path_uni(char *str)
{
	int	i = 0, j, k, l, len;
	char	*path = NULL;
	l_node	*list = NULL, *aux = NULL;

	if (!str)
		return (NULL);
	list = val_to_ll("PATH");
	if (!list)
		return (NULL);
	aux = list;
	while (str[i])
		i++;
	while (aux)
	{
		j = 0;
		while (aux->str[j])
			j++;
		len = i + j + 1;
		path = malloc(sizeof(char) * len);
		if (!path)
		{
			free_list(list, 1);
			return (NULL);
		}
		for (k = 0; k < j; k++)
			path[k] = aux->str[k];
		for (l = 0; l < i; l++, k++)
			path[k] = str[l];
		path[k] = '\0';
		if (!access(path, F_OK))
		{
			free_list(list, 1);
			return (path);
		}
		free(path);
		path = NULL;
		aux = aux->next;
	}
	free_list(list, 1);
	return (NULL);
}

/**
 * val_to_ll- looks for the variable stored in name in environment
 * @name: variable name
 * Return: pointer to value of path if exists, NULL otherwise
 */
l_node *val_to_ll(char *name)
{
	char	*str = NULL;

	if (!name)
		return (NULL);
	str = get_var_env(name);
	if (!str)
		return (NULL);
	return (str_to_ll(str, ':'));
}

/**
 * get_var_env- finds a variable in eviron
 * @name: name of the variable
 * Return: pointer to the value of the variable, NULL if variable doesn't exist
 */
char *get_var_env(char *name)
{
	int	len = 0, i = 0;

	if (!name)
		return (NULL);
	while (name[len])
		len++;
	while (environ[i] && strncmp(environ[i], name, len))
		i++;
	return ((environ[i]) ? (&environ[i][len + 1]) : (NULL));
}
