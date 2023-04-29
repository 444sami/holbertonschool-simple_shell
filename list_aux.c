#include "shell.h"

/**
 * free_list- frees a words list
 * @l: words list
 * @flag: if 0 does't free words, frees otherwise
 * Return: NULL
 */
void *free_list(l_node *l, int flag)
{
	if (l)
	{
		free_list(l->next, flag);
		if (flag)
			free(l->str);
		free(l);
	}
	return (NULL);
}

/**
 * node_count- counts the amount of words
 * @l: list of words
 * Return: the amount of words
 */
int node_count(l_node *l)
{
	if (!l)
		return (0);
	else
		return (1 + node_count(l->next));
}

/**
 * print_list- prints a list of words
 * @l: list of words
 * Return: void
 */
void print_list(l_node *l)
{
	if (l)
	{
		printf("%s\n", l->str);
		print_list(l->next);
	}
}
