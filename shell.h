#ifndef MAIN_H
#define MAIN_H

#include "libraries.h"

/* Prototypes */

/* _simple_shell.c */
int main(int ac, char **av, char **env);
void interactive_mode(int mode, int ac, char **av, char **env);

/* aux_func.c */
char **cmd_to_arg(void);

#endif
