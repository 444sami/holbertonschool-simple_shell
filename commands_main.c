#include "shell.h"

#define buffsize 8192

/**
 * cmds_inter- reads input andtrans forms it into a list
 * Return: list of commands
 */
l_node *cmds_inter()
{
	int	i;
	char	buf[buffsize];
	l_node	*l = NULL;

	for (i = 0; i < buffsize; i++)
		buf[i] = '\0';
	read(STDIN_FILENO, buf, buffsize);
	l = str_to_ll(buf, '\n');
	return (l);
}

/**
 * args_arr- makes an argv
 * @l: list input
 * Return: argv
 */
char **args_arr(l_node *l)
{
	int	amount, i;
	char	**args = NULL;
	l_node	*aux = NULL;

	amount = node_count(l);
	args = malloc(sizeof(char **) * (amount + 1));
	if (!args)
		return (NULL);
	aux = l;
	for (i = 0; i < amount; i++)
	{
		args[i] = aux->str;
		aux = aux->next;
	}
	args[i] = NULL;
	free_list(l, 0);
	return (args);
}
