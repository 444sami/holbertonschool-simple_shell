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
 * @word: the word
 * @len: words length
 * @next: next word
 */
typedef struct word_list
{
	char *word;
	int len;
	struct word_list *next;
} l_node;


/*---->     Prototypes     <----*/

/* _simple_shell.c */
int main(int ac, char **av, char **env);
int check_builtin(char ***cmds, int pos);

/* aux_func.c */
char ***cmd_to_arg(void);
char ***free_cmds(char ***cmds);

/* err.c */
void err_han(char *s1, char *s2);

/* built_in.c */
void exit(int val);
void print_env(char **env);

/* lowa.c */
l_node *create_list(char *str, int *pos);

/* lowb.c */
void *free_list(l_node *l, int flag);
int words_counter(l_node *l);
void print_list(l_node *l);

#endif
