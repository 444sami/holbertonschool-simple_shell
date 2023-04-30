#include "shell.h"

/**
 * main- runs the shell
 * Return: 0 on success, non-zero otherwise
 */
int main(void)
{
	int	mode;
	char	**cmd = NULL;
	l_node	*cmds = NULL, *aux = NULL, *argv = NULL;

	mode = isatty(STDIN_FILENO);
	do {
		if (mode)
			write(STDOUT_FILENO, "$ ", 2);
		cmds = cmds_inter();
		path_remake(cmds);
		if (cmds)
		{
			aux = cmds;
			while (aux)
			{
				argv = str_to_ll(aux->str, ' ');
				cmd = args_arr(argv);
				if (aux->next)
					exe_cmd(cmd, 1);
				else
					exe_cmd(cmd, mode);
				free_args(cmd);
				cmd = NULL;
				aux = aux->next;
			}
			free_list(cmds, 1);
		}
	} while (mode);
	return (0);
}

/**
 * exe_cmd- executes the command passed
 * @cmd: command
 * @mode: interactive or not
 * Return: void
 */
void exe_cmd(char **cmd, int mode)
{
	int	wstatus;
	char	*pc = NULL, *str = NULL;

	(void)pc;
	(void)str;
	if (cmd)
	{
		if (!access(cmd[0], F_OK))
		{
			if (!mode || ((fork()) ? (!wait(&wstatus)) : 1))
				execve(cmd[0], cmd, environ);
		}
	}
}
