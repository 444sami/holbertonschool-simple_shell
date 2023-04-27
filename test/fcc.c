#include "shell.h"

/**
 * free_commander- frees the commander
 * @:cmds: commander to be freed
 * Return: void
 */
void free_commander(char ***cmds)
{
	int i = 0;

	if (cmds)
		while (cmds[i])
		{
			free_cmd(cmds[i]);
			i++;
		}
	free(cmds);
}

/**
 * free_cmd- frees command and args
 * @cmd: command to be freed
 * Return: void
 */
void free_cmd(char **cmd)
{
	int i = 0;

	if (cmd)
		while (cmd[i])
		{
			free_word(cmd[i]);
			i++;
		}
	free(cmd);
}

/** free_word- frees words
 * @str: word to be freed
 * Return: void
 */
void free_word(char *str)
{
	free(str);
}
