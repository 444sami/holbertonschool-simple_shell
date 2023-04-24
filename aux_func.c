#include "shell.h"
#include <stdio.h>
#define buffsize 4096

/**
 * cmd_to_arg- splits a str into the differents commands
 * Return: pointer to the array of commands, NULL otherwise
 */
char **cmd_to_arg(void)
{
	int	wc, i;
	ssize_t	len;
	char	buff[buffsize], **cmds;
	wl_t	*l, *aux;

	len = read(0, buff, buffsize);
	if (len == -1)
		return (NULL);
	l = create_list(buff);
	if (!l)
		return (NULL);
	wc = words_counter(l);
	cmds = malloc(sizeof(char *) * (wc + 1));
	if (!cmds)
	{
		free_list(l, 1);
		return(NULL);
	}
	aux = l;
	for (i = 0; i < wc; i++)
	{
		cmds[i] = aux->word;
		aux = aux->next;
	}
	cmds[i] = NULL;
	free_list(l, 0);
	return (cmds);
}

int main(void)
{
	write(1, "$ ", 2);
	char **cmds = cmd_to_arg();
	int i = 0;
	while (cmds[i])
	{
		printf("%s\n", cmds[i]);
		i++;
	}
	return (0);
}
