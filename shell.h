#ifndef SHELL_H
#define SHELL_H


/*---->    Included Libraries    <----*/
#include <sys/wait.h>

#include <unistd.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*---->    Structures    <----*/

/**
 * struct word_list- a list of words
 * @str: the string
 * @next: next node
 */
typedef struct word_list
{
	char *str;
	struct word_list *next;
} l_node;


/*---->     Variables    <----*/
extern char **environ;


/*---->     Prototypes     <----*/

/* _simple_shell.c */
void exe_cmd(char **cmd, int mode, l_node *cmds);

/* built_in.c */
int check_built(char **cmd, l_node *cmds);
void env_imp(void);
void exit_imp(int status, char **cmd, l_node *cmds);

/* path_main.c */
void path_remake(l_node *list);
char *path_uni(char *str);
l_node *val_to_ll(char *name);
char *get_var_env(char *name);

/* cmds.c */
l_node *cmds_inter();
char **args_arr(l_node *l);
void free_args(char **args);
void print_args(char **args);

/* list_commands.c */
l_node *str_to_ll(char *buf, char dem);
void add_end(l_node *l, l_node *a);

/* list_aux.c */
void *free_list(l_node *l, int flag);
int node_count(l_node *l);
void print_list(l_node *l);

#endif
