#include "shell.h"

/**
 * create_list- creates a list of words
 * @str: the string which contains the words
 * Return: a pointer to the list
 */
wl_t *create_list(char *str)
{
	int	pos = 0, f, i;
	wl_t	*l = NULL, *aux = NULL, *aux2 = NULL;

	if (!str)
		return (NULL);
	while (str[pos])
	{
		if (str[pos] > 32)
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
			f = pos;
			while (str[f] > 32)
				f++;
			aux->len = f - pos + 1;
			aux->word = malloc(sizeof(char) * aux->len);
			if (!aux->word)
				return (free_list(l, 1));
			for (i = 0; pos < f; i++, pos++)
				aux->word[i] = str[pos];
			aux->word[i] = '\0';
			if (!l)
			{
				l = aux;
				aux2 = l;
			}
		}
		pos++;
	}
	return (l);
}
