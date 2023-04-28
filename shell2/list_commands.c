#include "shell.h"

/**
 * command_str- creates a string which contain the command and arguments
 * @buf: buffer where is the input
 * Return: a list of the commands
 */
l_node *command_str(char *buf)
{
	int	i = 0, f, k, len;
	l_node	*l = NULL, *aux = NULL;

	if (!buf)
		return (NULL);
	while (buf[i] != '\0')
	{
		if (buf[i] <= 32)
			i++;
		else
		{
			f = i;
			while (buf[f] != '\0' && buf[f] != '\n')
				f++;
			len = f - i;
			aux = malloc(sizeof(l_node));
			if (!aux)
				return (free_list(l, 1));
			aux->next = NULL;
			aux->word = NULL;
			aux->word = malloc(sizeof(char) * (len + 1));
			if (!aux->word)
			{
				free(aux);
				return (free_list(l, 1));
			}
			for (k = 0; i < f; i++, k++)
				aux->word[k] = buf[i];
			aux->word[k] = '\0';
			if (!l)
				l = aux;
			else
				add_end(l, aux);
		}
	}
	return (l);
}

/**
 * add_end- adds a node at the end of the list
 * @l: original list
 * @a: node to be added
 * Return: void
 */
void add_end(l_node *l, l_node *a)
{
	l_node *aux = NULL;

	if (l)
	{
		aux = l;
		while (aux->next)
			aux = aux->next;
		aux->next = a;
	}
}
