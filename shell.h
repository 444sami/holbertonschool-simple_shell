#ifndef MAIN_H
#define MAIN_H

#include "libraries.h"

/* Prototypes */

/* _simple_shell.c */
int main(int ac, char **av, char **envron);

/* aux_func.c */
char **cmd_to_arg(void);
char **free_cmds(char **cmds);

/* err.c */
void err_han(char *s1, char *s2);

/* built_in.c */

#endif
