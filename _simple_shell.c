#include "shell.h"

/**
 * main- runs the shell
 * @ac: amount of arguments
 * @av: list of arguments
 * @env: environment variables
 * Return: 0 on success, non-zero otherwise
 */
int main(int ac, char **av, char **env)
{
	int	mode, wstatus;
	char	**cmd = NULL;
	l_node	*cmds = NULL, *aux = NULL, *argv = NULL;

	(void)ac;
	(void)av;
	(void)env;
	(void)wstatus;
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
				argv = args_str(aux->word);
				cmd = args_arr(argv);
				if  (aux->next)
					exe_cmd(cmd, 1, &wstatus, env);
				else
					exe_cmd(cmd, mode, &wstatus, env);
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
 * @wstatus: for wait function
 * @env: environ
 * Return: void
 */
void exe_cmd(char **cmd, int mode, int *wstatus, char **env)
{
	if (cmd)
		if (!access(cmd[0], F_OK))
		{
			if (!mode || ((fork()) ? (!wait(wstatus)) : 1))
				execve(cmd[0], cmd, env);
		}
}
