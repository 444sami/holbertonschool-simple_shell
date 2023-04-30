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
		if (cmds)
		{
			aux = cmds;
			while (aux)
			{
				argv = str_to_ll(aux->str, ' ');
				path_remake(argv);
				cmd = args_arr(argv);
				if (aux->next)
					exe_cmd(cmd, 1, cmds);
				else
					exe_cmd(cmd, mode, cmds);
				free_args(cmd);
				cmd = NULL;
				aux = aux->next;
			}
			free_list(cmds, 1);
		}
	} while (mode);
	return (errno);
}

/**
 * exe_cmd- executes the command passed
 * @cmd: command
 * @mode: interactive or not
 * @cmds: list of commands
 * Return: void
 */
void exe_cmd(char **cmd, int mode, l_node *cmds)
{
	int	wstatus;

	if (cmd)
	{
		if (!access(cmd[0], F_OK))
		{
			if (!mode || ((fork()) ? (!wait(&wstatus)) : 1))
				if (execve(cmd[0], cmd, environ))
					errno = 2;
		}
		else
		{
			errno = 127;
			if (check_built(cmd, cmds))
			{
				fprintf(stderr, "./hsh: 1: %s: not found\n", cmd[0]);
			}
		}
	}
}
