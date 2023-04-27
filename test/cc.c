#include "shell.h"

#define buffsize 4096

/**
 * commander- creates an array of command with the corresponding arguments
 * Return: array of commands
 */
char ***commander(void)
{
	int	i = 0, j = 0, k;
	char	buff[buffsize], ***cmds = NULL;

	read(STDIN_FILENO, buff, buffsize);
	while (buff[i])
		if (buff[i] == '\n' && buff[i + 1] != '\0')
			j++;
	j += 2;
	cmds = malloc(sizeof(char **) * j);
	if (!cmds)
		return (NULL);
	for (k = 0; k < j; k++)
		cmds[k] = NULL;
	while (buff[i])
	{
		while (buff[i] <= 32)
			i++;
		cmds[k] = cmd(buff, &i);
		if (!cmds[k])
		{
			free_commander(cmds);
			return (NULL);
		}
		k++;
	}
	return (cmds);
}

/**
 * cmd- splits the buffer into the different commands
 * @buff: contains all the commnads and args
 * @pos: position in buffer
 * Return: an array of command and its arguments
 */
char **cmd(char *buff, int *pos)
{
	int	i = *pos, f = i, k;
	char	*cmdstr = NULL, **comm = NULL;

	while (buff[f] && buff[f] != '\n')
		f++;
	cmdstr = malloc(sizeof(char) * (f - i + 1));
	if (!cmdstr)
		return (NULL);
	for (k = 0; i < f; i++, k++)
		cmdstr[k] = buff[i];
	cmdstr[k] = '\0';
	*pos = i;
	comm = cmd_to_arg(cmdstr);
	free(cmdstr);
	return (comm);
}

/**
 * cmd_to_arg- splits a str into the differents commands
 * @str: string to be splited
 * Return: pointer to the array of commands, NULL otherwise
 */
char **cmd_to_arg(char *str)
{
	int	i, len;
	char	**cmds = NULL;
	l_node	*l = NULL, *aux = NULL;

	l = create_list(str);
	if (!l)
		return (NULL);
	len = words_counter(l) + 1;
	cmds = malloc(sizeof(char *) *  len);
	if (!cmds)
	{
		free_list(l, 1);
		return (NULL);
	}
	aux = l;
	for (i = 0; i < len; i++)
	{
		cmds[i] = aux->word;
		aux = aux->next;
	}
	cmds[i] = NULL;
	free_list(l, 0);
	return (cmds);
}
