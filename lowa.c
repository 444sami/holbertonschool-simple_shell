#include "shell.h"

/**
 * create_list- creates a list of words
 * @str: the string which contains the words
 * @pos: position to start
 * Return: a pointer to the list
 */
l_node *create_list(char *str, int *pos)
{
	int	p = *pos, f, i;
	l_node	*l = NULL, *aux = NULL, *aux2 = NULL;

	if (!str)
		return (NULL);
	while (str[p] != '\n' && str[p] != '\0')
	{
		if (str[p] > 32)
		{
			aux = malloc(sizeof(wl_t));
			if (!aux)
				return (free_list(l, 1));
			aux->next = NULL;
			if (aux2)
			{
				aux2->next = aux;
				aux2 = aux2->next;
			}
			f = p;
			while (str[f] > 32)
				f++;
			aux->len = f - p + 1;
			aux->word = malloc(sizeof(char) * aux->len);
			if (!aux->word)
				return (free_list(l, 1));
			for (i = 0; p < f; i++, p++)
				aux->word[i] = str[p];
			aux->word[i] = '\0';
			if (!l)
			{
				l = aux;
				aux2 = l;
			}
		}
		p++;
	}
	*pos = p;
	return (l);
}
